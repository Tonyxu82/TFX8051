/* Byte Vector
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
 * vec.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef struct byte_vector bvector;
struct byte_vector{
	byte* data;
	int size;
	int	r_index;
	int w_index;
};

bvector* create_bvector(int size){

	if(size<1) return NULL;

	bvector* bv = (bvector*)malloc(sizeof(bvector));
	if(!bv) return NULL;

	bv->data = (byte*)malloc(size);
	if(!bv->data){
		free(bv);
		return NULL;
	}

	bv->size = size;
	bv->r_index = 0;
	bv->w_index = 0;
}

void delete_bvector(bvector* bv){
	
	if(!bv) return;

	if(bv->data) free(bv->data);

	free(bv);
}

int push_back(bvector* bv, byte a){
	if(!bv) return -1;
	if(bv->w_index == bv->size) return -1;

	bv->data[bv->w_index++] = a;

	return 0;
}


int get_next(bvector* bv){
	if(!bv) return -1;

	if(bv->r_index<bv->w_index){
		return bv->data[bv->r_index++];
	}

	return -1;
}

void print_bvector(bvector* bv){
	if(!bv) return;
	if(!bv->size) return;

	int i = bv->size;

	while(i){
		printf("%d ", bv->data[bv->size - i]);
		i--;
	}
	printf("\n");
}

int main(int argc, char** argv){
	bvector* bv = create_bvector(300);

	int i =0;
	for(i=0; i<300; i++){
		push_back(bv, (byte)i);
	}

	print_bvector(bv);

	for(i=0; i<10; i++){
		printf("%d ", get_next(bv));
	}
	printf("\n");

	delete_bvector(bv);

	return 0;

}