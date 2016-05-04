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
 * tfx_list.h
 * 
 */

#ifndef _TFX_LIST_H_
#define _TFX_LIST_H_

//node of a structure
typedef struct node node;
struct node{
	int val;
	node* next;
};

//list
typedef struct list list;
struct list{
	node* head;
	node* tail;
	int   size;
};

//insert a node at the tail of a list
int push_back(list* l, node* n);

//insert a node at the head of a list
int push_head(list* l, node* n);

//fetch the head of a list
node* pop(list* l);

//create a list
list* create_list();

//delelete a list
void delete_list(list* l);

//get the size of the list
int get_list_size(list* l);

//print the content of the list
void print_list(list* l);

#endif //_TFX_LIST_H_