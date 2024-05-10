#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct node {
	char* item;
	struct node* next;
} node;

int isEmpty(node* head)
{
	if (head == NULL) 
		return 1;
	return 0;
}

char* get_item(node* head, int pos)
{
	node* cur_node = head;
	int count;

	for (count = 0; count < pos; count++) 
		cur_node = cur_node->next;

	return cur_node->item;
}

node* insertnode(node* head, char* item, int pos)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->item = item;

	node* pre_node = head;
	node* pos_node = head;
	int count;

	for (count = 0; count < pos - 1; count++) 
		pre_node = pre_node->next;
	for (count = 0; count < pos; count++)
		pos_node = pos_node->next;
	//insert at begin
	if (pos == 0)
	{
		newnode->next = head;
		head = newnode;
	}
	else
	{
		//insert at end
		if (pos_node == NULL)
		{
			newnode->next = NULL;
			pre_node->next = newnode;
		}
		//insert at middle
		else
		{
			newnode->next = pos_node;
			pre_node->next = newnode;
		}
	}

	return head;
}

node* deletenode(node* head, int pos)
{
	node* deleted_node;
	node* pre_node = head;
	node* pos_node = head;
	int count;

	for (count = 0; count < pos - 1; count++) 
		pre_node = pre_node->next;
	for (count = 0; count < pos; count++) 
		pos_node = pos_node->next;
	// 맨 앞에서 삭제
	if (pos == 0)
	{
		deleted_node = head;
		head = head->next;
		free(deleted_node);
	}
	// 중간&맨 뒤에서 삭제
	else
	{
		deleted_node = pos_node;
		pre_node->next = pos_node->next;
		free(deleted_node);
	}

	return head;
}

