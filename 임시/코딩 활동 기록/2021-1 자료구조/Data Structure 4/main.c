#include "dheap.h"

void main() {
	dheap* heap = NULL;
	heap = create(heap, "h1.txt", 3);
	
	/* print array
	   1 2 6 4 10 7 8 15 19 25
	   -1 0 1 -1 3 -1 2 5 6 -1 4 -1 -1 -1 -1 7 -1 -1 -1 8 -1 -1 -1 -1 -1 9 -1 -1 -1 -1 */
	print_heap(heap);

	//print dheap is valid : 1
	printf("dheap is valid : %d\n", valid(heap->heap_array, heap->current_size, heap->d));

	// print parent node of heap_array[5] : 2 (heap_array[5] is 7)
	printf("parent node of heap_array[5] : %d\n", parent(heap, 5));
	// print parent node of heap_array[7] : 6 (heap_array[7] is 15)
	printf("parent node of heap_array[7] : %d\n", parent(heap, 7));

	// print 0th child node of heap_array[1] : 10
	printf("0th child node of heap_array[1] : %d\n", ichild(heap, 1, 0));
	// print 1th child node of heap_array[2] : 19
	printf("1th child node of heap_array[2] : %d\n", ichild(heap, 2, 1));

	// print findmin : 1
	printf("findmin : %d\n", findmin(heap));

	insert(heap, 5);
	/* print array
	   1 2 6 4 10 7 8 15 19 25 5
	   -1 0 1 - 1 3 10 2 5 6 - 1 4 - 1 - 1 - 1 - 1 7 - 1 - 1 - 1 8 - 1 - 1 - 1 - 1 - 1 9 - 1 - 1 - 1 - 1 */
	print_heap(heap);
	insert(heap, 3);
	/* print array
	   1 2 6 3 10 7 8 15 19 25 5 4
       -1 0 1 3 11 10 2 5 6 -1 4 -1 -1 -1 -1 7 -1 -1 -1 8 -1 -1 -1 -1 -1 9 -1 -1 -1 -1 */
	print_heap(heap);

	// deletemin: 1
	printf("deletemin : %d\n", deletemin(heap));
     /* print array
		2 4 6 3 10 7 8 15 19 25 5
	    - 1 - 1 0 3 1 10 2 5 6 - 1 4 - 1 - 1 - 1 - 1 7 - 1 - 1 - 1 8 - 1 - 1 - 1 - 1 - 1 9 - 1 - 1 - 1 - 1 */
	print_heap(heap);
	
	// deleteitem : 15
	printf("deleteitem : %d\n", deleteitem(heap, 15));
	/* print array
	   2 4 5 3 10 7 8 6 19 25
	   -1 -1 0 3 1 2 7 5 6 -1 4 -1 -1 -1 -1 -1 -1 -1 -1 8 -1 -1 -1 -1 -1 9 -1 -1 -1 -1 */
	print_heap(heap);

	// deleteitem : 7
	printf("deleteitem : %d\n", deleteitem(heap, 7));
	/* print array
	   2 4 5 3 10 25 8 6 19
	   -1 -1 0 3 1 2 7 -1 6 -1 4 -1 -1 -1 -1 -1 -1 -1 -1 8 -1 -1 -1 -1 -1 5 -1 -1 -1 -1 */
	print_heap(heap);

	dheap* mdheap = NULL;
	mdheap = create(mdheap, "h2.txt", 3);
	/* print array
	   1 9 20 11 15
	   -1 0 -1 -1 -1 -1 -1 -1 -1 1 -1 3 -1 -1 -1 4 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 */
	print_heap(mdheap);
	merge(heap, mdheap);
	/* print array
	  1 4 2 3 10 25 8 6 19 5 9 20 11 15
	  -1 0 2 3 1 9 7 -1 6 10 4 12 -1 -1 -1 13 -1 -1 -1 8 11 -1 -1 -1 -1 5 -1 -1 -1 -1 */
	print_heap(heap);

	dereasekey(heap, 10, 7);
	/* print array
   	  1 4 2 3 7 25 8 6 19 5 9 20 11 15
	  -1 0 2 3 1 9 7 4 6 10 -1 12 -1 -1 -1 13 -1 -1 -1 8 11 -1 -1 -1 -1 5 -1 -1 -1 -1 */
	print_heap(heap);

}