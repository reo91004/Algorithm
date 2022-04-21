#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 연결리스트 생성
typedef struct node
{
    long long item;
    struct node *next;
} node;

int main()
{
    FILE *fp = fopen("input.txt", "r");

    // 총 노드와 현재 노드를 선언
    node *NumList = NULL;
    node *cur = NULL;

    // 임시로 값을 받을 변수, 5000이상 수 카운트 변수, 노드 길이 변수 선언
    long long item = 0;
    int cntOver5000 = 0;
    int cntlen = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%lld", &item);

        node *tempnode = (node *)malloc(sizeof(node));
        tempnode->item = item;
        tempnode->next = NULL;

        // cntlen을 증가할 지 결정하는 변수
        int index = 0;

        if (tempnode->item > 5000)
            cntOver5000++;

        // 첫 번째 노드 삽입시
        if (NumList == NULL)
        {
            NumList = tempnode;
            cur = NumList;
            index = 1;
        }
        else
        {
            node *cur = NumList;
            node *pre = NULL;

            // 정렬하면서 노드를 삽입하도록 한다.
            while (cur != NULL)
            { // 현재 숫자가 들어온 숫자보다 작으면
                if (cur->item < tempnode->item)
                { // 현재 노드의 다음 노드가 비어있다면 삽입한다.
                    if (cur->next == NULL)
                    {
                        cur->next = tempnode;
                        index = 1;
                        break;
                    }
                    // 다음 노드가 비어있지 않다면 이동한다.
                    pre = cur;
                    cur = cur->next;
                }
                // 현재 숫자가 들어온 숫자보다 작으면
                else if (cur->item > tempnode->item)
                { // 이전 노드가 비어있다면 임시 노드의 다음을 현재 노드로 바꾸고 NumList 갱신
                    if (pre == NULL)
                    {
                        tempnode->next = cur;
                        NumList = tempnode;
                    }
                    else
                    { // 이전 노드가 비어있지 않다면 중간에 삽입한다.
                        tempnode->next = cur;
                        pre->next = tempnode;
                    }
                    index = 1;
                    break;
                }
                else // 중복이라면 카운트도 하지않고 멈춘다.
                {
                    index = 0;
                    break;
                }
            }
        }
        
        if (index)
            cntlen++;
    }

    printf("The total number of nodes: %d\n", cntlen);
    printf("More than 5000 values: %d", cntOver5000);

    free(NumList);
    fclose(fp);
}