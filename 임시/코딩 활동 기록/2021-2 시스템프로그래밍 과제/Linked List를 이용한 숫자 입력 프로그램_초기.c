#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 연결리스트 생성
typedef struct node {
	long long item;
	struct node* next;
} node;

// 중복을 제거하는 함수, 더 좋은 방법이 있을지는 모르겠지만 시간이 오래 걸림.
void removing(node* head)
{
	// 이전 노드, 현재 노드, 임시 노드 생성
	node* pre, * cur, * tempnode;
	pre = head;

	// 이전 노드가 NULL이 아닐 때까지만 (이전 노드가 처음부터 시작되므로)
	while (pre != NULL)
	{
		cur = pre; // cur이 일단 pre가 되어야 시작하게 됨

		// 밑에 if문에서 cur->next의 item까지 탐색하는 코드가 있으므로 cur->next가 NULL일때 종료
		while (cur->next != NULL) // 현재 노드의 다음 노드가 NULL이 아닐 때까지
		{ // 맨 처음 실행 시 cur이 pre이므로 이후부터 검사해서 cur만 오른쪽으로 움직이게 됨
			if (pre->item == cur->next->item)
			{ // 만약 중복되면, 해당 노드를 삭제하고 연결
				tempnode = cur->next;
				cur->next = cur->next->next;
				free(tempnode);
			}
			else
				cur = cur->next;
		}

		pre = pre->next; // 다음 노드부터, 다시 반복
	}
}

// 연결리스트 길이 측정
int length(node* cur) {
	int cntlen = 0;

	while (cur != NULL)
	{
		cur = cur->next;
		cntlen++;
	}

	return cntlen;
}

// 메인 함수
int main()
{
	FILE* fp = fopen("input.txt", "r");

	// 총 노드와 현재 노드를 선언
	node* NumList = (node*)malloc(sizeof(node));
	node* cur = NULL;

	// 임시로 값을 받을 변수,  5000 이상 수 카운트 변수 선언
	long long t_item = 0;
	int cntOver5000 = 0;

	while (!feof(fp))
	{
		fscanf(fp, "%lld", &t_item);

		node* tempnode = (node*)malloc(sizeof(node));
		tempnode->item = t_item;
		tempnode->next = NULL;

		// 5000 이상일 시 카운트 올리기
		if (tempnode->item > 5000)
			cntOver5000++;

		if (cur == NULL) // NumList가 비어있다면
		{
			NumList = tempnode; // 먼저 tempnode 값을 NumList에 넣고
			cur = NumList; // 그 NumList를 cur에 넣는다.
		}
		else // 노드가 이미 하나 이상 있다면
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