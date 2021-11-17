#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// 이제부터 스네이크 기법 이용하도록 노력해보자.

// 연결리스트 생성
typedef struct node {
    long long item;
    struct node *next;
} node;

// 같은 값이 있는지 찾아 return한 값에 따라 노드 삽입 여부를 결정한다.
int find_same(node *NumList, long long item)
{
    node *tempnode = NumList;
    while (tempnode != NULL)
    {
        if (tempnode->item == item)
            return 1;

        tempnode = tempnode->next;
    }

    return 0;
}

// 모든 노드를 동적할당 해제한다.
void free_all_node(node *head)
{
    node *tempnode = head;
    while (head != NULL)
    {
        head = head->next;
        free(tempnode);
        tempnode = head;
    }
}

int main()
{
    FILE *fp = fopen("input.txt", "r");

    node *NumList = NULL;

    long long item = 0;
    int cntOver5000 = 0;
    int cntlen = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%lld", &item);

        if (item > 5000)
            cntOver5000++;

        // 중복인 값이 있다면 continue로 아예 넘어간다.
        if (find_same(NumList, item))
            continue;

        // 중복인 값이 없다면 그때서야 tempnode를 생성함으로써 실행시간을 빠르게 한다.
        node *tempnode = (node *)malloc(sizeof(node));
        tempnode->item = item;
        tempnode->next = NULL;

        tempnode->next = NumList;
        NumList = tempnode;
        cntlen++;
    }

    printf("The total number of nodes: %d\n", cntlen);
    printf("More than 5000 values: %d", cntOver5000);

    free_all_node(NumList);
    fclose(fp);
    return 0;
}
