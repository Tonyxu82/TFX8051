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
 * tfx_test.c
 * 
 */

#include "tfx_test.h"
#include <string.h>

test_suite* create_test_suite(){

 	test_suite* ts = (test_suite*) malloc(sizeof(test_suite));
 	if(!ts) goto cts_exception;

 	memset(ts->desc, 0, TEST_DESC_MAX_SIZE);
 	memset(ts->file, 0, TEST_FIRMWARE_NAME);

 	ts->test_cases = (list*)malloc(sizeof(list));
 	if(!ts->test_cases) goto cts_exception;

 	ts->aCPU 	 = NULL;
 	ts->success  = 0;
 	ts->fail 	 = 0;
 	ts->coverage = 0;

 	return ts;

cts_exception:
	if(ts->test_cases)
		free(ts->test_cases);
 	if(ts)
 		free(ts);

 	return NULL;
 }


//delete a test suite
void delete_test_suite(test_suite* ts){

	if(!ts) return;


	if(ts->test_cases){
		node* n = ts->test_cases->head;
		while(n){
			node* tmp = n;
			n = n->next;
			//we need free void* p_val first
			free(tmp);
		}

		free(ts->test_cases);
	}

	free(ts);
	ts=NULL;
}

test* create_test(){
	test* t = (test*)malloc(sizeof(test));
	if(!t) goto ct_exception;

	int i = 0;
	for(i=0; i<4; i++){
		t->in[i] = NULL;
		t->in_size[i] = 0;
		t->in_cur_loc[i] = 0;

		t->out[i] = NULL;
		t->out_size[i] = 0;
		t->out_cur_loc[i] = 0;

		t->expect[i] = NULL;
		t->expect_size[i] = 0;
		t->expect_cur_loc[i] = 0;
	}

	t->status = NOTEXE;

	return t;

ct_exception:
	return NULL;

}

void delete_test(test* t){
	if(!t) return;

	int i = 0;
	for(i=0; i<4; i++){
		if(t->in[i]){
			free(t->in[i]);
			t->in[i] = NULL;
 		}

 		if(t->out[i]){
			free(t->out[i]);
			t->out[i] = NULL;
 		}

 		if(t->expect[i]){
			free(t->expect[i]);
			t->expect[i] = NULL;
 		}

	}
}

test* init_test(int in_size, int out_size){
	//create a test case
	test* t = create_test();
	if(!t){
		printf("failed to create a test case!");
		return NULL;
	}

	//Assume t get 10 input from P0 and output result from P2
	t->in[0] = (byte*)malloc(in_size);
	t->in_size[0] = in_size;
	t->out[2] = (byte*)malloc(out_size);
	t->out_size[2] = out_size;
	t->expect[2] = (byte*)malloc(out_size);
	t->expect_size[2] = out_size;
	
	return t;
}

void fprintf_test_suite(FILE* fp, test_suite* ts){

}

void fprint_test_case(FILE* fp, test* t){

}