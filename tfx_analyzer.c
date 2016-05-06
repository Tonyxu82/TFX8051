/* Disassember & Coverage Analyzing Tools
 * Copyright 2016 Lai Xu (Tony)
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject 
 * to the following conditions: 
 *
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software. 
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE. 
 *
 * (i.e. the MIT License)
 *
 * tfx_analyzer.h
 * 
 */


#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "emu8051.h"

int enable_coverage = 1;

//8051 Core
core_8051* cur_core = NULL;

core_8051* create_core(){
  core_8051* core = (core_8051*)malloc(sizeof(core_8051));
  memset(core, 0, sizeof(core_8051));
    core->mCodeMem     = malloc(65536);
    core->mCodeMemSize = 65536;
    core->mExtData     = malloc(65536);
    core->mExtDataSize = 65536;
    core->mLowerData   = malloc(128);
    core->mUpperData   = malloc(128);
    core->mSFR         = malloc(128);
    core->except       = NULL;
    core->sfrread      = NULL;
    core->sfrwrite     = NULL;
    core->xread = NULL;
    core->xwrite = NULL;

    if(enable_coverage){
      core->mCodeCov = (int*)malloc(sizeof(int)*core->mCodeMemSize);
      for(int i = 0; i<core->mCodeMemSize; i++){
        core->mCodeCov[i] = -1;  //-1 - not use this pc
      }
    }else{
      core->mCodeCov = NULL;
    }

    reset(core, 1);

    return core;
}

//free memory allocated to the core 8051
#define FREE_CORE_MEM(mem) { \
                if(mem){ \
                  free(mem); \
                  mem = NULL; \
                } \
               }

void delete_core(core_8051* core){

  if(!core) return;

  FREE_CORE_MEM(core->mCodeMem);
  FREE_CORE_MEM(core->mExtData);
  FREE_CORE_MEM(core->mLowerData);
  FREE_CORE_MEM(core->mUpperData);
  FREE_CORE_MEM(core->mSFR);
  FREE_CORE_MEM(core->mCodeCov);

  core = NULL;
}

int load_fw(core_8051* core, char *fw)
{
    FILE *f;    
    char assembly[128];
    if (fw == 0 || fw[0] == 0)
        return -1;
    f = fopen(fw, "r");
    if (!f) return -1;
    if (fgetc(f) != ':')
    {
        fclose(f);
        return -2; // unsupported file format
    }
    while (!feof(f))
    {
        int recordlength;
        int address;
        int recordtype;
        int checksum;
        int i;
        recordlength = readbyte(f);
        address = readbyte(f);
        address <<= 8;
        address |= readbyte(f);
        recordtype = readbyte(f);
        if (recordtype == 1)
            return 0; // we're done
        if (recordtype != 0)
            return -3; // unsupported record type
        checksum = recordtype + recordlength + (address & 0xff) + (address >> 8); // final checksum = 1 + not(checksum)
        for (i = 0; i < recordlength; i++)
        {
            int data = readbyte(f);
            checksum += data;
            core->mCodeMem[address + i] = data;

            if(core->mCodeCov){
                core->mCodeCov[address + i] = 0;
            }
        }

        i = readbyte(f);
        checksum &= 0xff;
        checksum = 256 - checksum;
        if (i != (checksum & 0xff))
            return -4; // checksum failure

        decode(cur_core, address, assembly);
        printf("%-5d %s\n",address + i, assembly);
        while (fgetc(f) != ':' && !feof(f)) {} // skip newline        
    }
    fclose(f);
    return -5;
}

int main(int argc, char *argv[])
{ 
  int ch, prev, row, col;
  int y, x;


  if(argc != 2)
  {
    printf("Usage: %s <firmware>\n", argv[0]);
    exit(1);
  }

  cur_core = create_core();

  if(load_fw(cur_core, argv[1])) return -1;

  // for(int i=0; i<cur_core->mCodeMemSize; i++){
  //   if(cur_core->mCodeMem[i]){
  //     decode(cur_core, i, assembly);
  //     printf("%-5d %s\n",i, assembly);
  //   }
  // }
  
  // initscr();                      
  // getmaxyx(stdscr, row, col);      



  // printw("<-Press Any Key->"); 
  // getch();
  // endwin();                         /* End curses mode */


  delete_core(cur_core);

  return 0;
}