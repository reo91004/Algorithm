#ifndef __MY_STRING_H__
#define __MY_STRING_H__

typedef struct node {
	char character;
	struct node* next;
} node;

typedef struct my_string {
	struct node* first_symbol;
} my_string;

my_string to_mystring(char* string);
void print_mystring(my_string str);
my_string my_strcpy(my_string destination, my_string source);
my_string my_strncat(my_string destination, my_string source, int num);
int my_strcmp(my_string str1, my_string str2);
int my_strlen(my_string str);
int my_strchr(my_string str, int character);
int my_strcspn(my_string str1, my_string str2);
int my_strstr(my_string str1, my_string str2);
my_string my_strrev(my_string str);
#endif