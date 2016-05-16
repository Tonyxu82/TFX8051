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
#include "jsmn.h"
#include <string.h>
#include <errno.h>

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

static inline void *realloc_it(void *ptrmem, size_t size) {
	void *p = realloc(ptrmem, size);
	if (!p)  {
		free (ptrmem);
		fprintf(stderr, "realloc(): errno=%d\n", errno);
	}
	return p;
}

test* read_test(char* tf){
	if(!tf) goto rt_exception;

	FILE* fp = 	fopen(tf, "r");
	if(!fp) goto rt_exception;
	
	char buf[BUFSIZ];
	int r, i, j, s, data_size;
	char* js = NULL;
	size_t jslen = 0;

	jsmn_parser p;
	jsmntok_t *tok;
	size_t tokcount = 2;

	jsmn_init(&p);

	tok = malloc(sizeof(*tok) * tokcount);
	if (tok == NULL) {
		fprintf(stderr, "malloc(): errno=%d\n", errno);
		goto rt_exception;
	}

	r = fread(buf, 1, sizeof(buf), fp);

	js = realloc_it(js, jslen+r+1);
	if(!js) goto rt_exception;

	strncpy(js+jslen, buf, r);
	jslen = jslen + r;

again:
	r = jsmn_parse(&p, js, jslen, tok, tokcount);
	if (r < 0) {
		if (r == JSMN_ERROR_NOMEM) {
			tokcount = tokcount * 2;
			tok = realloc_it(tok, sizeof(*tok) * tokcount);
			if (tok == NULL) {
				goto rt_exception;
			}

			goto again;
		}
	} 

	test*  t = malloc(sizeof(test));
	if(!t) goto rt_exception;
	memset(t, 0, sizeof(test));

	//name
	tok+=2;
	snprintf(t->name, TEST_NAME, "%.*s", tok->end - tok->start, js+tok->start);
	printf("TEST NAME: %s\n", t->name);


	//desc
	tok+=2;
	snprintf(t->desc, TEST_DESC_MAX_SIZE, "%.*s", tok->end - tok->start, js+tok->start);
	printf("TEST DESC: %s\n", t->desc);

	//file
	tok+=2;
	snprintf(t->file, TEST_FIRMWARE_NAME, "%.*s", tok->end - tok->start, js+tok->start);
	printf("TEST FILE: %s\n", t->file);

	//get input
	tok+=2;
	s = tok->size;
	char pin_name[5];
	char pin_value[5];
	int pin_index = -1;
	for(i=0; i<s; i++){
		tok +=3;
		snprintf(pin_name, 5, "%.*s", tok->end - tok->start, js+tok->start);

		if(!strcmp("P0", pin_name)){
			pin_index = 0;
		}else if(!strcmp("P1", pin_name)){
			pin_index = 1;
		}else if(!strcmp("P2", pin_name)){
			pin_index = 2;
		}else if(!strcmp("P3", pin_name)){
			pin_index = 3;
		}else{
			goto rt_exception;
		}


		if(t->in[pin_index]){
			goto rt_exception;
		}

		//get data from input pin 
		tok +=2;
		t->in_size[pin_index] = tok->size;
		t->in[pin_index] = (byte*)malloc(t->in_size[pin_index]);

		data_size = tok->size;
		for(j=0; j<data_size; j++){
			tok ++;
			snprintf(pin_value, 5, "%.*s", tok->end - tok->start, js+tok->start);
			int tmp = atoi(pin_value);
			if(tmp<0 || tmp>255) goto rt_exception;
			t->in[pin_index][j] = (byte)tmp; 
		}

	}

	//get expect output array size
	tok+=2;
	s = tok->size;
	pin_index = -1;
	for(i=0; i<s; i++){
		tok +=3;
		snprintf(pin_name, 5, "%.*s", tok->end - tok->start, js+tok->start);

		if(!strcmp("P0", pin_name)){
			pin_index = 0;
		}else if(!strcmp("P1", pin_name)){
			pin_index = 1;
		}else if(!strcmp("P2", pin_name)){
			pin_index = 2;
		}else if(!strcmp("P3", pin_name)){
			pin_index = 3;
		}else{
			goto rt_exception;
		}


		if(t->expect[pin_index]){
			goto rt_exception;
		}

		//get data from output pin 
		tok +=2;
		t->expect_size[pin_index] = tok->size;
		t->out_size[pin_index] = tok->size;

		t->expect[pin_index] = (byte*)malloc(t->expect_size[pin_index]);
		memset(t->expect[pin_index], 0, t->expect_size[pin_index]);
		t->out[pin_index] = (byte*)malloc(t->out_size[pin_index]);
		memset(t->out[pin_index], 0, t->out_size[pin_index]);

		data_size = tok->size;
		for(j=0; j<data_size; j++){
			tok ++;
			snprintf(pin_value, 5, "%.*s", tok->end - tok->start, js+tok->start);
			int tmp = atoi(pin_value);
			if(tmp<0 || tmp>255) goto rt_exception;
			t->expect[pin_index][j] = (byte)tmp; 
		}
	}

	//get status
	char status[5];
	tok +=2;
	snprintf(status, 5, "%.*s", tok->end - tok->start, js+tok->start);

	t->status = atoi(status);

	return t;

rt_exception:
	if(fp){
		fclose(fp);
		fp = NULL;
	}

	return NULL;
}

void fprintf_test_suite(FILE* fp, test_suite* ts){

}

void fprint_test_case(FILE* fp, test* t){

}