#define _CRT_SECURE_NO_WARNINGS

#include "dictree.h"

// Print all dictree words.
void printall(dictree* dic, char* word) {
	dictree* curtree = dic;
	char* old_word = (char*)malloc(sizeof(char) * MAX_SIZE);
	strcpy(old_word, word);
	if (curtree->special == 1) {
		printf("%s\n", word);
	}

	for (int i = 0; i < 26; i++) {
		if (curtree->character[i] != NULL) {
			char dest[2];
			char newchar = (char)(i + 'a');
			dest[0] = newchar;
			dest[1] = '\0';
			strcat(word, dest);
			printall(curtree->character[i], word);
			strcpy(word, old_word);
		}
	}
}

void print_error() {
	printf("Error\n");
}

///////////// Don't touch /////////////

// Make dictree.
dictree* construct(dictree* dic, char* file) {

	FILE* fp = fopen(file, "r");
	int linecount = 0;
	char* buffer;
	char temp[MAX_SIZE];

	dic = (dictree*)malloc(sizeof(dictree));
	dic->special = 0;

	for (int i = 0; i < 26; i++)
	{
		dic->character[i] = NULL;
	}

	while (!feof(fp))
	{
		fgets(temp, MAX_SIZE, fp);
		linecount++;
	}

	char** words = (char*)malloc(sizeof(char) * linecount);
	fseek(fp, 0, SEEK_SET);

	for (int i = 0; i < linecount; i++) // 일단 단어들을 포인터 배열에 넣어버리기
	{
		buffer = (char*)malloc(sizeof(char) * linecount);
		fgets(buffer, MAX_SIZE, fp);
		words[i] = buffer;
	}

	for (int i = 0; i < linecount; i++)
		insert(dic, words[i]);

	fclose(fp);

	return dic;

}

// If word includes dictree, return 1
// Else return 0
int search(dictree* dic, char* word) {

	dictree* cur = dic;

	int count = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == '\n')
			break;
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		if (cur->character[(int)(word[i]) - 'a'] == NULL)
		{
			return 0;
		}

		cur = cur->character[(int)(word[i]) - 'a'];
	}

	if (cur->special == 1)
		return 1;
	else
		return 0;

}

// If any word includes dictree that starts with prefix word, return 1.
// Else return 0.
int prefixsearch(dictree* dic, char* word) {

	dictree* cur = dic;

	int count = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == '\n')
			break;
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		if (cur->character[(int)(word[i]) - 'a'] == NULL)
		{
			return 0;
		}

		cur = cur->character[(int)(word[i]) - 'a'];
	}

	return 1;

}

// If special is 0, return count number of non-special node.
// If special is 1, return count number of special node.
// else, call print_error.
int count_node(dictree* dic, int special) {

	if (special == 0)
	{
		int count = 0;
		int tempcount = 0;
		dictree* cur = dic;

		for (int i = 0; i < 26; i++)
		{
			if (cur->character[i] != NULL)  // 비어있지 않으면 알파벳 있음
			{
				if (cur->special == 0 && tempcount == 0) // 다시 내려가면서 할 중복 계산을 방지
				{
					count++;
					tempcount++;
				}

				count += count_node(cur->character[i], 0);
			}
		}

		return count;
	}
	else if (special == 1)
	{
		int count = 0;
		dictree* cur = dic;

		for (int i = 0; i < 26; i++)
		{
			if (cur->character[i] != NULL)
			{
				if (cur->character[i]->special == 1)
				{
					count++;
				}

				count += count_node(cur->character[i], 1);
			}
		}

		return count;
	}
	else
	{
		print_error();
	}

}

// Insert word in current dictree, and return dictree.
dictree* insert(dictree* dic, char* word) {

	dictree* cur = dic;

	int count = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == '\n')
			break;
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		if (cur->character[(int)(word[i]) - 'a'] == NULL)
		{
			dictree* temptree = (dictree*)malloc(sizeof(dictree));
			temptree->special = 0;
			for (int j = 0; j < 26; j++)
			{
				temptree->character[j] = NULL;
			}
			cur->character[(int)(word[i]) - 'a'] = temptree;
		}

		cur = cur->character[(int)(word[i]) - 'a'];
	}

	cur->special = 1;

	return dic;

}

dictree* delete (dictree* dic, char* word) {

	dictree* pre = NULL;
	dictree* cur = dic;

	int count = 0;
	int checkleaf = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == '\n')
			break;
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		pre = cur;
		cur = cur->character[(int)(word[i]) - 'a'];
	}

	// ~ 일단 해당 단어까지 내려가기

	if (search(dic, word) == 0) // 단어가 아닐 때
	{
		return dic;
	}
	else // 단어일 때
	{
		for (int i = 0; i < 26; i++) // leaf node인지 확인
		{
			if (cur->character[i] != NULL) // leaf node가 아니면 special을 0으로 만들고 return
			{
				checkleaf = 1; // checkleaf가 1이면 leaf node가 아님
				break;
			}
		}

		if (checkleaf == 1) // leaf가 아니면
		{
			cur->special = 0;
			return dic;
		}
		else // leaf면
		{
			do {
				cur = NULL;
				cur = dic;

				for (int j = 0; j < count - 1; j++)
				{
					pre = cur;
					cur = cur->character[(int)(word[j]) - 'a'];
				}

				count--;

			} while (cur->special != 1);

			cur->character[(int)(word[count]) - 'a'] = NULL;

			return dic;
		}
	}

}