#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "graph.h"

typedef struct NODE {
	int data;
	struct NODE* next;
}NODE;

typedef struct {
	NODE* front, * rear;
}QUEUE;

void queuecreate(QUEUE* q);
int queueisEmpty(QUEUE* q);
void enqueue(QUEUE* q, int item);
int dequeue(QUEUE* q);

#endif