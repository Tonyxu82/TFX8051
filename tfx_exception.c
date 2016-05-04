/* Linked List
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
 * tfx_exception.c
 * 
 */

#include "tfx_exception.h"
#include "tfx_common.h"


void tfx_exception(core_8051* core, int err_code)
{

    switch (err_code)
    {
    // case EXCEPTION_IRET_SP_MISMATCH:
    //     if (opt_exception_iret_sp) return;
    //     break;
    // case EXCEPTION_IRET_ACC_MISMATCH:
    //     if (opt_exception_iret_acc) return;
    //     break;
    // case EXCEPTION_IRET_PSW_MISMATCH:
    //     if (opt_exception_iret_psw) return;
    //     break;
    // case EXCEPTION_ACC_TO_A:
    //     if (!opt_exception_acc_to_a) return;
    //     break;
    // case EXCEPTION_STACK:
    //     if (!opt_exception_stack) return;
    //     break;
    // case EXCEPTION_ILLEGAL_OPCODE:
    //     if (!opt_exception_invalid) return;
    //     break;
    }
}