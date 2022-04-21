#include "myString.h"

#include <stdio.h>
#include <stdlib.h>

// Convert C style string to my_string.
// The last node always corresponds to NULL character.
my_string to_mystring(char* string) {

	int count = 0;
	my_string* newnode = (my_string*)malloc(sizeof(my_string));
	node* tempnode;
	node* cur;

	while (string[count]) // NULL문자까지만 (= 문자 길이)
	{
		count++;
	}

	tempnode = (node*)malloc(sizeof(node) * (count + 1)); // apple이면 count=5, NULL문자 저장까지 6

	for (int i = 0; i <= count; i++)
	{
		(tempnode + i)->character = string[i]; // apple이면 tempnode->character = a, tempnode + 5->character = NULL
		(tempnode + i)->next = NULL;
	}

	newnode->first_symbol = tempnode;
	cur = newnode->first_symbol;

	for (int i = 1; i <= count; i++)
	{
		cur->next = (tempnode + i);
		cur = cur->next;
	}

	return *newnode;

	free(newnode);
	free(tempnode);
}

// Print str.
void print_mystring(my_string str) {

	node* cur = str.first_symbol;

	while (cur != NULL)
	{
		printf("%c", cur->character);
		cur = cur->next;
	}

	printf("\n");

}

// Return the legnth of str
int my_strlen(my_string str) {

	node* cur = str.first_symbol;
	int count = 0;

	while (cur->character != NULL)
	{
		cur = cur->next;
		count++;
	}

	return count;
}

// Copy from source to destination.
// If length of destination is smaller than legnth of source, print error message and return any my_string.
my_string my_strcpy(my_string destination, my_string source) {

	node* origin = source.first_symbol;
	node* copy = destination.first_symbol;
	node* temp;
	my_string* newnode = (my_string*)malloc(sizeof(my_string));

	int origin_len = my_strlen(source);
	int copy_len = my_strlen(destination);

	if (origin_len > copy_len)
	{
		printf("my_strcpy error");
		printf("\n");
		return source;
	}
	else
	{
		for (int i = 0; i < copy_len; i++)
		{
			(copy + i)->character = (origin + i)->character;
			(copy + i)->next = (origin + i)->next;
			if ((copy + i)->character == NULL) break;
		}
		newnode->first_symbol = copy;
		return *newnode;
	}

	free(newnode);

}

// Concatenate first num characters of source from the destination.
my_string my_strncat(my_string destination, my_string source, int num) {

	node* origin = source.first_symbol;
	node* copy = destination.first_symbol;
	node* temp;
	my_string* newnode = (my_string*)malloc(sizeof(my_string));

	int origin_len = my_strlen(source);
	int copy_len = my_strlen(destination);
	int count = 0;

	newnode->first_symbol = copy;

	if (origin_len < num)
	{
		for (int i = 0; i < copy_len; i++)
		{
			copy = copy->next;
		}

		copy->character = origin->character;
		copy->next = origin->next;
	}
	else
	{
		node* cur = origin;
		for (int i = 0; i < num; i++)
		{
			cur = cur->next;
		}

		cur->character = NULL;
		cur->next = NULL;

		for (int i = 0; i < copy_len; i++)
		{
			copy = copy->next;
		}

		copy->character = origin->character;
		copy->next = origin->next;
	}

	return *newnode;

	free(newnode);

}

// Compare str1 and str2.
// Return 0 : They are same.
// Return -1 : str1 precedes str2 in the prior order.
// Return 1 : str2 precedes str1 in the prior order.
int my_strcmp(my_string str1, my_string str2) {

	node* tempnode1 = str1.first_symbol;
	node* tempnode2 = str2.first_symbol;
	node* cur;

	int temp1_len = my_strlen(str1);
	int temp2_len = my_strlen(str2);

	int count = 0;

	if (temp1_len == temp2_len)
	{
		for (int i = 0; i < temp1_len; i++)
		{
			if (tempnode1->character == tempnode2->character)
			{
				count++;
				tempnode1 = tempnode1->next;
				tempnode2 = tempnode2->next;
			}
			else break;
		}

		if (count == temp1_len) return 0;
		else if (((tempnode1->character >= 'a' && tempnode1->character <= 'z') || (tempnode1->character >= 'A' && tempnode1->character <= 'Z')) && ((tempnode2->character >= 'a' && tempnode2->character <= 'z') || (tempnode2->character >= 'A' && tempnode2->character <= 'Z')))
		{
			if (tempnode1->character - tempnode2->character > 0) return -1;
			else return 1;
		}
		else if (tempnode1->character - tempnode2->character < 0) return -1;
		else return 1;
	}
	else
	{
		while (tempnode1->character == tempnode2->character)
		{
			tempnode1 = tempnode1->next;
			tempnode2 = tempnode2->next;
		}

		if (((tempnode1->character >= 'a' && tempnode1->character <= 'z') || (tempnode1->character >= 'A' && tempnode1->character <= 'Z')) && ((tempnode2->character >= 'a' && tempnode2->character <= 'z') || (tempnode2->character >= 'A' && tempnode2->character <= 'Z')))
		{
			if (tempnode1->character - tempnode2->character > 0) return -1;
			else return 1;
		}
		else if (tempnode1->character - tempnode2->character < 0) return -1;
		else return 1;
	}
}

// Search character in str.
// If such character exists, return the first index.
// Otherwise, return the length of str.
int my_strchr(my_string str, int character) {

	char ascii = (char)character;
	node* tempnode = str.first_symbol;

	int templen = my_strlen(str);

	for (int i = 0; i < templen; i++)
	{
		if (tempnode->character == ascii) return i;
		tempnode = tempnode->next;
	}
}

// Find the first index of str1 which contains any character in str2.
// Otherwise return lenght of str1.
int my_strcspn(my_string str1, my_string str2) {

	node* tempnode1 = str1.first_symbol;
	node* tempnode2 = str2.first_symbol;

	int temp1_len = my_strlen(str1);
	int temp2_len = my_strlen(str2);

	int count, temp;
	int min = temp1_len;

	for (int i = 0; i < temp2_len; i++)
	{
		tempnode1 = str1.first_symbol;
		count = 0;

		for (int j = 0; j < temp1_len; j++)
		{
			if (tempnode1->character == tempnode2->character) break;
			count++;
			tempnode1 = tempnode1->next;
		}

		if (min > count) min = count;
		tempnode2 = tempnode2->next;
	}

	return min;

}

// Check if str1 contains str2 as a substring.
// If contains, return first index in str1.
// Otherwise, return -1.
int my_strstr(my_string str1, my_string str2) {

	node* tempnode1 = str1.first_symbol;
	node* tempnode2 = str2.first_symbol;
	my_string newnode;

	int temp1_len = my_strlen(str1);
	int temp2_len = my_strlen(str2);

	int count = 0; // 처음부터 문자열을 아예 비교

	while (temp1_len >= temp2_len)
	{
		node* cur = tempnode1;
		node* compare = tempnode2;
		int temp1_num = 0, temp2_num = 0; // 아래 두 for문을 빠져나올 때의 값

		for (int i = 0; i < temp1_len; i++) // while문을 돌 수록 temp1_len은 하나씩 줄어들고 tempnode1의 연결리스트가 하나씩 삭제됨.
		{
			if (cur->character == compare->character) break; // 같은 문자를 찾으면 다음으로
			cur = cur->next;
			temp1_num++;
		}

		if (temp1_num == temp1_len)
		{
			return -1;
		}
		else
		{
			for (int i = 0; i < temp2_len; i++)
			{
				if (cur->character != compare->character) break; // 비교하다 문자가 다르면 break
				cur = cur->next;
				compare = compare->next;
				temp2_num++;
			}

			if (temp2_num == temp2_len) return temp1_num + count;
		}

		tempnode1 = tempnode1->next;
		temp1_len--;
		count++;
	}

	return -1;

}

// Reverse str
my_string my_strrev(my_string str) {

	my_string* newnode = (my_string*)malloc(sizeof(my_string));
	node* origin = str.first_symbol;
	node* reverse = (node*)malloc(sizeof(node));
	node* temp;

	int temp_len = my_strlen(str);

	while (origin != NULL)
	{
		temp = origin->next;
		origin->next = reverse;
		reverse = origin;
		origin = temp;
	}

	newnode->first_symbol = reverse;

	for (int i = 0; i < temp_len + 1; i++)
	{
		reverse = reverse->next;
	}

	reverse->character = NULL;
	reverse->next = NULL;

	return *newnode;

	free(reverse);
	free(newnode);

}