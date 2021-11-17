#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���Ḯ��Ʈ ����
typedef struct node {
	long long item;
	struct node* next;
} node;

// �ߺ��� �����ϴ� �Լ�, �� ���� ����� �������� �𸣰����� �ð��� ���� �ɸ�.
void removing(node* head)
{
	// ���� ���, ���� ���, �ӽ� ��� ����
	node* pre, * cur, * tempnode;
	pre = head;

	// ���� ��尡 NULL�� �ƴ� �������� (���� ��尡 ó������ ���۵ǹǷ�)
	while (pre != NULL)
	{
		cur = pre; // cur�� �ϴ� pre�� �Ǿ�� �����ϰ� ��

		// �ؿ� if������ cur->next�� item���� Ž���ϴ� �ڵ尡 �����Ƿ� cur->next�� NULL�϶� ����
		while (cur->next != NULL) // ���� ����� ���� ��尡 NULL�� �ƴ� ������
		{ // �� ó�� ���� �� cur�� pre�̹Ƿ� ���ĺ��� �˻��ؼ� cur�� ���������� �����̰� ��
			if (pre->item == cur->next->item)
			{ // ���� �ߺ��Ǹ�, �ش� ��带 �����ϰ� ����
				tempnode = cur->next;
				cur->next = cur->next->next;
				free(tempnode);
			}
			else
				cur = cur->next;
		}

		pre = pre->next; // ���� ������, �ٽ� �ݺ�
	}
}

// ���Ḯ��Ʈ ���� ����
int length(node* cur) {
	int cntlen = 0;

	while (cur != NULL)
	{
		cur = cur->next;
		cntlen++;
	}

	return cntlen;
}

// ���� �Լ�
int main()
{
	FILE* fp = fopen("input.txt", "r");

	// �� ���� ���� ��带 ����
	node* NumList = (node*)malloc(sizeof(node));
	node* cur = NULL;

	// �ӽ÷� ���� ���� ����,  5000 �̻� �� ī��Ʈ ���� ����
	long long t_item = 0;
	int cntOver5000 = 0;

	while (!feof(fp))
	{
		fscanf(fp, "%lld", &t_item);

		node* tempnode = (node*)malloc(sizeof(node));
		tempnode->item = t_item;
		tempnode->next = NULL;

		// 5000 �̻��� �� ī��Ʈ �ø���
		if (tempnode->item > 5000)
			cntOver5000++;

		if (cur == NULL) // NumList�� ����ִٸ�
		{
			NumList = tempnode; // ���� tempnode ���� NumList�� �ְ�
			cur = NumList; // �� NumList�� cur�� �ִ´�.
		}
		else // ��尡 �̹� �ϳ� �̻� �ִٸ�
		{
			cur->next = tempnode;
			cur = cur->next;
		}
	}

	removing(NumList);
	int len = length(NumList);

	printf("The total number of nodes: %d\n", len);
	printf("More than 5000 values: %d", cntOver5000);

	free(NumList);
	fclose(fp);
}