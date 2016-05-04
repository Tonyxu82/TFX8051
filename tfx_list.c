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
 * tfx_list.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "tfx_list.h"

int push_back(list* l, node* n){
	
	if(!l||!n){
		return -1;
	}

	if(!l->size){
		l->head = n;
		l->tail = n;
		l->tail->next = NULL;
		l->size = 1;
		return 0;
	}

	l->tail->next = n;
	l->tail = n;
	l->tail->next = NULL;
	l->size++;

	return 0;
}

int push_head(list* l, node* n){

	if(!l||!n){
		return -1;
	}

	if(!l->size){
		l->head = n;
		l->tail = n;
		l->tail->next = NULL;
		l->size = 1;
		return 0;
	}

	n->next = l->head;
	l->head = n;
	l->size++;

	return 0;
}

node* pop(list* l){
	
	if(!l) 		 return NULL;
	if(!l->size) return NULL;
	node* n = l->head;
	l->head = n->next;
	l->size--;

	return n;
}

list* create_list(){
	list* l = (list*)malloc(sizeof(list));
	return l;
}

void delete_list(list* l){
	if(!l) return;

	node* c = l->head;
	while(c){
		node* tmp = c;
		c = c->next;
		free(tmp);
	}

	free(l);
}

int get_list_size(list* l){
	if(!l){
		return 0;
	}

	return l->size;
}

void print_list(list* l){
	if(!l){
		return;
	}

	node* c = l->head;
	while(c){
		printf("%d->", c->val);
		c = c->next;
	}
	printf("null\n");
}
