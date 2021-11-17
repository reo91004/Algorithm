#include "dictree.h"

char word[MAX_SIZE] = "";

int main() {
	// construct
	dictree* dic = NULL;
	dic = construct(dic, "sample.txt");
	
	// print all words
	printall(dic, word);
	/* 
	   a
	   and
	   are
	   code
	   coder
	   coding
	*/

	// search
	int is_qwc_search = search(dic, "qwc");
	// print is_qwc_search : 0
	printf("is_qwc_search : %d\n", is_qwc_search);

	int is_and_search = search(dic, "and");
	// print is_and_search : 1
	printf("is_and_search : %d\n", is_and_search);

	// prefixsearch
	int is_a_prefixsearch = prefixsearch(dic, "a");
	// print is_a_prefixsearch : 1 ("a" is prefix : "a")
	printf("is_a_prefixsearch : %d\n", is_a_prefixsearch);

	int is_co_prefixsearch = prefixsearch(dic, "co");
	// print is_co_prefixsearch : 1 ("code" is prefix : "c", "co", "cod", "code")
	printf("is_co_prefixsearch : %d\n", is_co_prefixsearch);

	int is_um_prefixsearch = prefixsearch(dic, "um");
	// print is_um_prefixsearch : 0
	printf("is_um_prefixsearch : %d\n", is_um_prefixsearch);

	// insert
	dic = insert(dic, "mom");
	dic = insert(dic, "codeine");

	printall(dic, word);
	/*
	   a
	   and
	   are
	   code
	   codeine
	   coder
	   coding
	   mom
	*/

	// count_node
	int zero = count_node(dic, 0);
	// print count number of non-special node : 12
	printf("count number of non-special node : %d\n", zero);
	
	int one = count_node(dic, 1);
	// print count number of special node : 8
	printf("count number of special node : %d\n", one);
	
	// print error
	int two = count_node(dic, 2);

	//delete
	dic = delete(dic, "and");
	dic = delete(dic, "coder");
	dic = delete(dic, "are");

	printall(dic, word);
	/*
	   a
	   are
	   code
	   codeine
	   coding
	   mom
	*/
	int check_zero = count_node(dic, 0);
	int check_one = count_node(dic, 1);
	// print count number of non-special node : 11
	printf("count number of non-special node : %d\n", check_zero);
	// print count number of special node : 6
	printf("count number of special node : %d\n", check_one);
}