#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

void queuecreate(QUEUE* q) {
	q->front = NULL;
	q->rear = NULL;
}

int queueisEmpty(QUEUE* q) {
	if (q->front == NULL) {
		//printf("empty");
		return 1;
	}
	else return 0;
}

void enqueue(QUEUE* q, int item)
{
	NODE *newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->data = item;
	newNODE->next = NULL;

	if (queueisEmpty(q)) {
		q->front = newNODE;
		q->rear = newNODE;
	}

	else {
		q->rear->next = newNODE;
		q->rear = newNODE;
	}

}

int dequeue(QUEUE* q)
{
	NODE* deletedNODE = q->front;
	int item = deletedNODE->data;

	if (deletedNODE->next == NULL) {
		q->front = NULL;
		q->rear = NULL;
	}
	else {
		q->front = q->front->next;
	}

	free(deletedNODE);
	return item;
}