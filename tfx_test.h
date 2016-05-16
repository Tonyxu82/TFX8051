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
 * tfx_test.h
 * 
 */

#ifndef _TFX_TEST_H_
#define _TFX_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include "emu8051.h"
#include "tfx_list.h"
#include "tfx_common.h"

#define TEST_STATUS_NOTEXE    0
#define TEST_STATUS_SUCCESS   1
#define TEST_STATUS_FAIL	  2
#define TEST_NAME             64
#define TEST_DESC_MAX_SIZE 	  256
#define TEST_FIRMWARE_NAME    64

typedef enum test_status test_status;
enum test_status{
	NOTEXE,
	SUCCESS,
	FAIL
};

typedef struct test test;
struct test{

	char name[TEST_NAME];
	char desc[TEST_DESC_MAX_SIZE];
	char file[TEST_FIRMWARE_NAME];

	struct em8051 *aCPU;
	//input P0, P1, P2, P3
	byte *in[4];
	int in_size[4];
	int in_cur_loc[4];

	//output P0, P1, P2, P3
	byte *out[4];
	int out_size[4];
	int out_cur_loc[4];	
	
	//expect result P0, P1, P2, P3
	byte* expect[4];
	int expect_size[4];
	int expect_cur_loc[4];

	//status of this test case
	test_status status;
};


typedef struct test_suite test_suite;
struct test_suite{
	char desc[TEST_DESC_MAX_SIZE];
	char file[TEST_FIRMWARE_NAME];

	list *test_cases;
	
	struct em8051 *aCPU;

	int success;
	int fail;
	int coverage;
};

test_suite* create_test_suite();

void delete_test_suite(test_suite* ts);

int push_back_test_case(test_suite* ts, test* t);

test* pop_test_case(test_suite* ts);

test* create_test();

void delete_test(test* t);

//int init_test();
test* init_test(int in_size, int out_size);

test* read_test(char* tf);

void fprintf_test_suite(FILE* fp, test_suite* ts);

void fprint_test_case(FILE* fp, test* t);

#endif //_TFX_TEST_H_
