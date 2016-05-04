/* 8051 Firmware Test Framework
 * Copyright 2018 Lai Xu (Tony), Jari Komppa
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
 * tfx_io.c
 * 
 */
#include "tfx_io.h"

extern test*  cur_test;

#define TFX_P0 (REG_P0+0x80)
#define TFX_P1 (REG_P1+0x80)
#define TFX_P2 (REG_P2+0x80)
#define TFX_P3 (REG_P3+0x80)


int getP(int aRegister){

    int p = 0;
    if(aRegister == TFX_P0){
        p=0;
    }else if(aRegister == TFX_P1){
        p=1;
    }else if(aRegister == TFX_P2){
        p=2;
    }else if(aRegister == TFX_P3){
        p=3;
    }else{
        p=-1;
    }

    return p;
}

int tfx_sfrread(core_8051* core, int aRegister){

    
    int outputbye = -1;

    if(aRegister == TFX_P0 ||
       aRegister == TFX_P1 ||
       aRegister == TFX_P2 ||
       aRegister == TFX_P3){

        if(!cur_test){
            outputbye = core->mSFR[aRegister - 0x80];
            printf("SFRREAD %X FROM %X\n", outputbye, aRegister);
            return outputbye;
        }

        int p = getP(aRegister);

        if(p == -1) goto sfrr_exception;
        if(cur_test->in_cur_loc[p] >= cur_test->in_size[p])
            goto sfrr_exception;



        outputbye = cur_test->in[p][cur_test->in_cur_loc[p]++];
        core->mSFR[aRegister - 0x80] = outputbye;
        printf("SFRREAD %X FROM %X\n", outputbye, aRegister);
        return outputbye;
    }

    return core->mSFR[aRegister - 0x80];

sfrr_exception:
    return 0;

}

void tfx_sfrwrite(core_8051* core, int aRegister){


    if(aRegister == TFX_P0 ||
       aRegister == TFX_P1 ||
       aRegister == TFX_P2 ||
       aRegister == TFX_P3){

        if(!cur_test){
            printf("SFRWRITE %X TO %X\n", core->mSFR[aRegister-0x80], aRegister);
            return;
        }

        int p = getP(aRegister);
        if(p == -1) goto sfrw_exception;
        if(cur_test->out_cur_loc[p] >= cur_test->out_size[p])
            goto sfrw_exception;

        cur_test->out[p][cur_test->out_cur_loc[p]++] = core->mSFR[aRegister-0x80];
        printf("SFRWRITE %X TO %X\n", core->mSFR[aRegister-0x80], aRegister);
    }

sfrw_exception:
    return;

}
