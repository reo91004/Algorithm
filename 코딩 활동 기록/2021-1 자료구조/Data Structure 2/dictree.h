#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __DICTREE_H__
#define __DICTREE_H__
#define _CRT_SECURE_NO_WARNINGS
#define  MAX_SIZE 100

typedef struct dictree
{
	int special;             // 1 if the node is special
	struct dictree* character[26];  //character[i] = NULL if there is no i-th child
}dictree;

dictree* construct(dictree* dic, char* file);
int search(dictree* dic, char* word);
int prefixsearch(dictree* dic, char* word);
void printall(dictree* dic, char* word);
int count_node(dictree* dic, int special);
dictree* insert(dictree* dic, char* word);
dictree* delete (dictree* dic, char* word);
#endif