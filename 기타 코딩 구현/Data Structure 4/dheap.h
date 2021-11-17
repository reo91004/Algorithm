#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef __DHEAP_H__
#define __DHEAP_H__
#define _CRT_SECURE_NO_WARNINGS
#define  MAX_SIZE 30

typedef struct dheap
{
	int d; // maximum degree of heap
	int current_size; // current size of the heap
	int heap_array[MAX_SIZE]; // MAX_SIZE is defined in dheap.h
	int position_array[MAX_SIZE]; // stores the position where the values 0¡¦MAX-1 are stored in heap_array
}dheap;

void print_heap(dheap* h);
int is_empty(dheap* h);
void print_error();
dheap* create(dheap* h, char *file, int d);
int valid(int* A, int size, int d);
int parent(dheap* h, int index);
int ichild(dheap* h, int index, int i);
int findmin(dheap* h);
void insert(dheap* h, int item);
int deletemin(dheap* h);
void merge(dheap* h1, dheap* h2);
int deleteitem(dheap* h, int item);
void dereasekey(dheap* h, int item, int key);
#endif