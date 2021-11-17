#ifndef __STACK_H__
#define __STACK_H__

#include "graph.h"

typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct STACK{
	node* top;
}STACK;

void stackcreate(STACK* s);
int stackisEmpty(STACK* s);
void push(STACK* s, int item);
int pop(STACK* s);
int top(STACK* s);

#endif