#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __GRAPH_H__
#define __GRAPH_H__
#define MAX_VERTICES 100

typedef struct Graph {
	int n;   //number of vertices
	int m;  //size of E and W (number of edges * 2)
	int* O;
	int* E;
	int* W;
}Graph;

void print_error();
void print_arrays(Graph* G);
int adjacent(Graph* G, int u, int v);
void construct(Graph* G, char* file);
void print_matrix(Graph* G);
void add_edge(Graph* G, int i, int j, int weight);
void delete_edge(Graph* G, int i, int j);
void print_lexdfs(Graph* G);
void print_lexbfs(Graph* G);
int is_connected(Graph* G);
int shortest_path(Graph* G, int source, int destination);
#endif