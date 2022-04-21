#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node* next;
} node;

typedef struct Graph
{
    int num_vertices;
    node* adj_list[MAX];
} Graph;

void init(Graph* g, int n)
{
    g->num_vertices = n;
    int i;

    for (int i = 0; i < n; i++)
        g->adj_list[i] = NULL;
}

void insert_edge(Graph* g, int v, int u)
{
    node* vertex_v;
    node* vertex_u;

    vertex_v = (node*)malloc(sizeof(node));
    vertex_u = (node*)malloc(sizeof(node));

    vertex_v->item = v;
    vertex_v->next = NULL;
    vertex_u->item = u;
    vertex_u->next = NULL;

    if (g->adj_list[v] == NULL)
        g->adj_list[v] = vertex_u;
    else // 그냥 맨 앞에 추가
    {
        vertex_u->next = g->adj_list[v];
        g->adj_list[v] = vertex_u;
    }

    if (g->adj_list[u] == NULL)
        g->adj_list[u] = vertex_v;
    else // 맨 앞에 추가
    {
        vertex_v->next = g->adj_list[u];
        g->adj_list[u] = vertex_v;
    }
}

void printGraph(Graph* g)
{
    node* cur = NULL;
    for (int i = 0; i < g->num_vertices; i++)
    {
        node* cur = g->adj_list[i];

        printf("%d의 인접 리스트 : ", i);

        while (cur != NULL)
        {
            printf("%d ", cur->item);
            cur = cur->next;
        }

        printf("\n");
    }
}

int adjacent(Graph* g, int v, int u)
{
    node* vertex = g->adj_list[v];

    while (vertex != NULL)
    {
        if (vertex->item == u)
            return 1;
        vertex = vertex->next;
    }
    return 0;
}

void printAdjvertex(Graph* g, int v) // Vertex u 와 adjacent한 모든 vertex 탐색
{
    node* cur = g->adj_list[v];

    printf("%d의 인접 리스트 : ", v);

    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }

    printf("\n");
}

void deg(Graph* g, int u) // deg(u) 답하기
{
    int cnt = 0;

    node* cur = g->adj_list[u];

    while (cur != NULL)
    {
        cnt++;
        cur = cur->next;
    }

    printf("%d와 인접한 vertex 수는 %d개 입니다.\n", u, cnt);
}

int main()
{
    Graph g;
    int n;

    printf("리스트의 총 크기를 입력하시오 (4 이상) : ");
    scanf("%d", &n);
    init(&g, n);

    insert_edge(&g, 0, 1); // 일단 실행되는지 확인하기 위해
    insert_edge(&g, 0, 3);

    while (1)
    {
        int val;
        int u, v;

        printf("\n1 : 전체 리스트 출력\n2 : u와 v 인접한지 체크\n3 : Vertex u와 인접한 모든 Vertex 탐색\n4 : deg(u)\n5 : 종료\n숫자를 입력하세요 : ");
        scanf("%d", &val);

        switch (val)
        {
            case 1:
                printGraph(&g);
                break;
            case 2:
                printf("숫자 2개를 입력하세요 : ");
                scanf("%d %d", &u, &v);
                if (adjacent(&g, v, u))
                    printf("인접합니다.\n");
                else
                    printf("인접하지 않습니다.\n");
                break;
            case 3:
                printf("숫자 하나를 입력하세요 : ");
                scanf("%d", &v);
                printAdjvertex(&g, v);
                break;
            case 4:
                printf("숫자 하나를 입력하세요 : ");
                scanf("%d", &u);
                deg(&g, u);
                break;
            case 5:
                exit(1);
        }
    }

    printGraph(&g);

    return 0;
}