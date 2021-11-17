#define _CRT_SECURE_NO_WARNINGS

#include "dheap.h"

void print_heap(dheap* h) {

	printf("print array\n");
	for (int i = 0; i < h->current_size; i++) {
		printf("%d ", h->heap_array[i]);
	}
	printf("\n");

	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", h->position_array[i]);
	}
	printf("\n");
}
int is_empty(dheap* h) {
	if (h->current_size > 0) return 0;
	return 1;
}

void print_error() {
	printf("Error\n");
}


///////////// Don't touch /////////////


dheap* create(dheap* h, char* file, int d) {
	
	FILE* fp = fopen(file, "r");
	int size;
	int *temparr;
	fscanf(fp, "%d", &size);

	h = (dheap*)malloc(sizeof(dheap));

	h->current_size = 0;
	h->d = d;

	temparr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		fscanf(fp, "%d", &temparr[i]);
	}

	for (int i = 0; i < size; i++)
	{
		insert(h, temparr[i]);
	}

	free(temparr);

	return h;
}

int valid(int* A, int size, int d) {
	
	if (size < MAX_SIZE)
	{
		int temp = 1;
		int parent = 0;
		int index = 1;
		int count = 0;

		while (temp < size)
		{
			while (count < 3)
			{
				if (A[parent] < A[index])
				{
					index++;
					parent = (index - 1) / d;
				}

				else
					return 0;

				count++;
				temp++;
			}

			count = 0;
			parent = temp / d;
		}

		return 1;
	}
}

int parent(dheap* h, int index) {
	
	if (h->heap_array[index] == NULL)
	{
		print_error();
	}
	else
	{
		return h->heap_array[(index - 1) / h->d];
	}
}

int ichild(dheap* h, int index, int i) {
	
	if (h->heap_array[(index * h->d) + i + 1] != NULL)
	{
		return h->heap_array[(index * h->d) + i + 1];
	}
	else
		print_error();
}

int findmin(dheap* h) {

	return h->heap_array[0];
}

void insert(dheap* h, int item) {
	
	if (h->current_size < MAX_SIZE) 
	{
		h->heap_array[h->current_size] = item;
		int temp;
		int parent = (h->current_size - 1) / h->d;
		int index = h->current_size;

		while (parent >= 0)
		{
			if (h->heap_array[parent] > h->heap_array[index]) 
			{
				temp = h->heap_array[parent];
				h->heap_array[parent] = h->heap_array[index];
				h->heap_array[index] = temp;
				index = parent;
				parent = (index - 1) / h->d;
			}

			else break;
		}

		h->current_size++;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		h->position_array[i] = -1;
	}
	
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < h->current_size; j++)
		{
			if (h->heap_array[j] == i)
				h->position_array[i] = j;
		}
	}
}

int deletemin(dheap* h) {

	if (is_empty(h))
		return -1;

	int exit = 0;
	int delete_item = h->heap_array[0];
	int new_root = h->heap_array[h->current_size - 1];
	h->heap_array[0] = new_root;
	h->current_size--;
	int index = 0;

	int* label = (int*)malloc(sizeof(int) * h->d);

	for (int i = 0; i < h->d; i++)
	{
		label[i] = i + 1;
	}

	int temp, min;

	while (1)
	{
		for (int i = 0; i < h->d; i++)
		{
			if (label[i] >= h->current_size)
			{
				exit = 1;
				break;
			}
		}

		if (exit == 1)
			break;

		min = index;

		for (int i = 0; i < h->d; i++)
		{
			if (label[i] < h->current_size && h->heap_array[label[i]] < h->heap_array[min])
				min = label[i];
		}

		if (min != index)
		{
			temp = h->heap_array[min];
			h->heap_array[min] = h->heap_array[index];
			h->heap_array[index] = temp;
			index = min;

			for (int i = 0; i < h->d; i++)
			{
				label[i] = (index * h->d) + 1;
			}
		}

		else break;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		h->position_array[i] = -1;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < h->current_size; j++)
		{
			if (h->heap_array[j] == i)
				h->position_array[i] = j;
		}
	}

	free(label);

	return delete_item;
}

void merge(dheap* h1, dheap* h2) {
	
	for (int i = 0; i < h2->current_size; i++)
	{
		insert(h1, h2->heap_array[i]);
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		h1->position_array[i] = -1;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < h1->current_size; j++)
		{
			if (h1->heap_array[j] == i)
				h1->position_array[i] = j;
		}
	}
}

int deleteitem(dheap* h, int item) {

	if (is_empty(h))
		return -1;

	int exit = 0;
	int index = 0;
	int pos = 0;

	if (h->position_array[item] != -1)
	{
		pos = h->position_array[item];
	}
	else
	{
		print_error();
	}

	index = (pos - 1) / h->d;

	int delete_item = h->heap_array[pos];

	h->heap_array[pos] = h->heap_array[h->current_size - 1];

	h->current_size--;

	int* label = (int*)malloc(sizeof(int) * h->d);

	for (int i = 0; i < h->d; i++)
	{
		label[i] = (index * h->d) + i + 1;
	}

	int temp, min;

	while (1)
	{
		for (int i = 0; i < h->d; i++)
		{
			if (label[i] >= h->current_size)
			{
				exit = 1;
				break;
			}
		}

		if (exit == 1)
			break;

		min = index;

		for (int i = 0; i < h->d; i++)
		{
			if (label[i] < h->current_size && h->heap_array[label[i]] < h->heap_array[min])
				min = label[i];
		}

		if (min != index)
		{
			temp = h->heap_array[min];
			h->heap_array[min] = h->heap_array[index];
			h->heap_array[index] = temp;
			index = min;

			for (int i = 0; i < h->d; i++)
			{
				label[i] = (index * h->d) + 1;
			}
		}

		else break;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		h->position_array[i] = -1;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < h->current_size; j++)
		{
			if (h->heap_array[j] == i)
				h->position_array[i] = j;
		}
	}

	free(label);

	return delete_item;
}

void dereasekey(dheap* h, int item, int key) {
	
	if (h->position_array[item] == -1)
	{
		print_error();
	}
	else
	{
		int temp = deleteitem(h, item);
		insert(h, key);
	}
}