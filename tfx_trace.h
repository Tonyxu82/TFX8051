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
 * tfx_trace.h
 * 
 */

#ifndef _TFX_TRACE_H_
#define _TFX_TRACE_H_

#include <stdio.h>
#include <unistd.h>
#include "emu8051.h"

typedef struct frame frame;
struct frame{
	unsigned char SFR[128];
	unsigned char LowerData[64];
	int pc;
};

FILE* trace_new(char* fw_name, char* trace_name);

void  trace_record(frame* fm, FILE* fp);

void  trace_replay(char* trace_name, core_8051* core);

void  trace_end(FILE* fp);

#endif //_TFX_TRACE_H_
