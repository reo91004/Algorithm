#include <stdio.h>

#include "myString.h"

int main() {
	// to_mystring
	my_string s1 = to_mystring("hello world");
	my_string s2 = to_mystring("da");
	// contains NULL in the middle !!
	my_string s3 = to_mystring("app\0le");  

	// print_mystring
	// print hello world
	print_mystring(s1);  
	// print da
	print_mystring(s2);
	// print app
	print_mystring(s3);
	
	// my_strlen
	// print 11
	printf("%d\n", my_strlen(s1));
	// print 2
	printf("%d\n", my_strlen(s2));
	// print 3
	printf("%d\n", my_strlen(s3));
	
	// my_strcpy
	my_string s4 = to_mystring("banananana");
	// print my_strcpy error (s2 is smaller than s4)
	my_string s5 = my_strcpy(s2, s4);
	my_string s6 = my_strcpy(s4, s2);
	// print da
	print_mystring(s6);
	// print app
	my_string s7 = my_strcpy(s1, s3);
	print_mystring(s7);
	
	// my_strncat
	s1 = to_mystring("abc");
	s2 = to_mystring("defddd");
	s1 = my_strncat(s1, s2, 2);
	// print abcde
	print_mystring(s1);

	s1 = to_mystring("abc");
	s2 = to_mystring("def");
	s1 = my_strncat(s1, s2, 3);
	// print abcdef
	print_mystring(s1);

	s1 = to_mystring("abc");
	s2 = to_mystring("def");
	s1 = my_strncat(s1, s2, 4);
	// print abcdef
	print_mystring(s1);
	
	// my_strcmp
	my_string apple = to_mystring("apple");
	my_string ABCapple = to_mystring("ABCapple");
	my_string ABC1pple = to_mystring("ABC1pple");
	my_string apple123 = to_mystring("apple123");
	my_string Apple = to_mystring("Apple");
	my_string aple = to_mystring("a ple");

	// 0 (same case)
	printf("%d\n", my_strcmp(apple, apple));
	// -1 (first one is precede : digit)
	printf("%d\n", my_strcmp(ABC1pple, ABCapple));
	// 1 (second one is precede : one includes the other)
	printf("%d\n", my_strcmp(apple123, apple));
	// -1 (first one is precede : uppercase letters are later than lowercase letters)
	printf("%d\n", my_strcmp(apple, Apple));
	// 1 (second one is precede : black letters precedes)
	printf("%d\n", my_strcmp(apple, aple));
	
	// my_strchr
	// print 1 (if char contains)
	printf("%d\n", my_strchr(apple, 112));
	// print 8 (if char doesn't contain, print length)
	printf("%d\n", my_strchr(ABCapple, '1'));
	// print 8 (NULL pointer is last position)
	printf("%d\n", my_strchr(ABC1pple, '\0'));
	
	// my_strcspn
	my_string bananan = to_mystring("bananan");
	my_string an = to_mystring("an");
	my_string nan = to_mystring("nan");
	my_string cc = to_mystring("cc");
	// print 0 (if char contains)
	printf("%d\n", my_strcspn(apple, an));
	// print 1 (if char contains multiple characters, return where first came out)
	printf("%d\n", my_strcspn(bananan, nan));
	// print 5 (if char does not contain, return length)
	printf("%d\n", my_strcspn(apple, cc));
	
	// my_strstr
	// print -1 (if char does not contain)
	printf("%d\n", my_strstr(apple, nan));
	// print 2 if char contains multiple times, 
	printf("%d\n", my_strstr(bananan, nan));
	my_string aaab = to_mystring("aaab");
	my_string aab = to_mystring("aab");
	// print 1 (Check again from the first letter)
	printf("%d\n", my_strstr(aaab, aab));
	my_string eqwe = to_mystring("eqwe");
	// print -1 (if char contains only one letter, return -1)
	printf("%d\n", my_strstr(apple, eqwe));

	// my_strrev
	my_string rev = my_strrev(bananan);
	// print nananab
	print_mystring(rev);
	// quite long string including white space
	my_string helloworldadada = to_mystring("hello world da da da");
	rev = my_strrev(helloworldadada);
	// print ad ad ad dlrow olleh
	print_mystring(rev);  
	// reverse one letter
	my_string e = to_mystring("e");
	rev = my_strrev(e);
	// print e
	print_mystring(rev);
	
	return 0;
	
}