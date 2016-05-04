/* 8051 Firmware Test Framework
 * Copyright 2018 Lai Xu (Tony)
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
 * tfx_trace.c
 * 
 */
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "tfx_trace.h"
#include "emu8051.h"

extern int opt_clock_hz;

FILE* trace_new(char* fw_name, char* trace_name){
	int file_series = 0;

	while(1){
		sprintf(trace_name, "trace/%s_trace_%.5i.bin", fw_name, file_series++);

		if( access(trace_name, F_OK ) != -1 ) {
			continue;
		} else {
			break;
		}
	}

	FILE* fp = fopen(trace_name, "wb");

	return fp;
}

void  trace_record(frame* fm, FILE* fp){
	fwrite(fm, sizeof(frame), 1, fp);
}

// void  trace_replay(char* trace_name, core_8051* core){
// 	frame fm;
// 	char assembly[128];
// 	printf("Replay %s\n", trace_name);
// 	FILE* fp = fopen(trace_name, "rb");
// 	int ticked = 1;

// 	while(fread(&fm, sizeof(frame), 1, fp) != 0){
// 		decode(core, fm.pc, assembly);
// 		printf("%-5d %s\n", fm.pc, assembly);
// 		core->mPC = fm.pc;
// 		memcpy(core->mSFR, fm.SFR, 128);
// 	    memcpy(core->mLowerData, fm.LowerData, 64);

// 	   	int targettime = getTick()+10;
// 		unsigned int targetclocks = (opt_clock_hz / 1200);
		
// 		do{
// 	       	targetclocks--;
//             ticked = tick(core);

//             if(ticked){
//             	break;
//             }
// 		}
// 		while(targettime > getTick() && 
// 			   targetclocks > 0);

//         while(targettime > getTick())
//         {
//             core_sleep(1);
//         }

// 	}
// }

void  trace_replay(char* trace_name, core_8051* core){
	frame fm[1000];
	char assembly[128];
	printf("Replay %s\n", trace_name);
	FILE* fp = fopen(trace_name, "rb");
	int ticked = 1;

	while(1){
		int n=fread(&fm, sizeof(frame), 1000, fp);
		if(!n) return;

		int i = 0;
		for(i=0; i<n; i++){
			//decode(core, fm[i].pc, assembly);
			//printf("%-5d %s\n", fm[i].pc, assembly);
			core->mPC = fm[i].pc;
			memcpy(core->mSFR, fm[i].SFR, 128);
		    memcpy(core->mLowerData, fm[i].LowerData, 64);

		   	int targettime = getTick()+10;
			unsigned int targetclocks = (opt_clock_hz / 1200);
			
			do{
		       	targetclocks--;
	            ticked = tick(core);

	            if(ticked){
	            	break;
	            }
			}
			while(targettime > getTick() && 
				   targetclocks > 0);

	        while(targettime > getTick())
	        {
	            core_sleep(1);
	        }
		}

	}
}

void  trace_end(FILE* fp){
	fclose(fp);
}