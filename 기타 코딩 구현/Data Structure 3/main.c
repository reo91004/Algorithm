#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

void main() {
	// construct
	Graph g;
	construct(&g, "sample.txt");
	print_arrays(&g);
	/*
	array O : 0 2 4 7 10 11 
	array E : 1 3 0 2 1 3 5 0 2 4 3 2
	array W : 8 4 8 7 7 10 5 4 10 20 20 5
	*/

	print_matrix(&g);
	/*
	0 1 0 1 0 0
	1 0 1 0 0 0
	0 1 0 1 0 1
	1 0 1 0 1 0
	0 0 0 1 0 0
	0 0 1 0 0 0
	*/

	printf("dfs : ");
	print_lexdfs(&g);
	// print 0 1 2 3 4 5
	printf("\n");

	printf("bfs: ");
	print_lexbfs(&g);
	// print 0 1 3 2 4 5
	printf("\n");

	// print connected : 1
	printf("connected : %d\n", is_connected(&g));

	printf("shortest path of edge(0,2)\n");
    printf("\n%d\n", shortest_path(&g, 0, 2));
	// print 0 3 2
    // print 14

	add_edge(&g, 7, 8, 9);
	// print error
	add_edge(&g, 1, 5, 6);
	print_arrays(&g);
	/*
	array O : 0 2 5 8 11 12
	array E : 1 3 0 2 5 1 3 5 0 2 4 3 1 2
	array W : 8 4 8 7 6 7 10 5 4 10 20 20 6 5
	*/

	delete_edge(&g, 1, 5);
	print_arrays(&g);
	/*
	array O : 0 2 4 7 10 11 
	array E : 1 3 0 2 1 3 5 0 2 4 3 2
	array W : 8 4 8 7 7 10 5 4 10 20 20 5
	*/
}