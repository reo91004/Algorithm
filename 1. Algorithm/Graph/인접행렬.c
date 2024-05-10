#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h> 

typedef struct Graph // Graph에서 Adjacency Matrix 구현
{
    int num_vertices;
    int adj_matrix[MAX][MAX];
} Graph;

void init(Graph* g, int n) // 모두 0으로 초기화함
{
    g->num_vertices = n;
    int i, j;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            g->adj_matrix[i][j] = 0;
    }
}

void insert_edge(Graph* g, int v, int u)
{
    g->adj_matrix[v][u] = 1;
    g->adj_matrix[u][v] = 1;
}

void printGraph(Graph* g)
{
    for (int i = 0; i < g->num_vertices; i++)
    {
        for (int j = 0; j < g->num_vertices; j++)
            printf("%d ", g->adj_matrix[i][j]);

        printf("\n");
    }
}

int adjacent(Graph* g, int v, int u) // Vertex u와 v 가 adjacent 한지 체크
{
    return g->adj_matrix[v][u];
}

void printAdjvertex(Graph* g, int v) // Vertex u 와 adjacent한 모든 vertex 탐색
{
    for (int i = 0; i < g->num_vertices; i++)
        if (g->adj_matrix[v][i] == 1)
            printf("%d ", i);

	printf("\n");
}

void deg(Graph* g, int u) // deg(u) 답하기
{
    int cnt = 0;

    for (int i = 0; i < g->num_vertices; i++)
        if (g->adj_matrix[u][i] == 1)
            cnt++;

    printf("%d와 인접한 vertex 수는 %d개 입니다.\n", u, cnt);
}

int main()
{
    Graph g;
    int n;

    printf("N*N 행렬의 행 크기를 입력하시오 (4 이상) : ");
    scanf("%d", &n);
    init(&g, n);

    insert_edge(&g, 0, 1); // 일단 실행되는지 확인하기 위해
    insert_edge(&g, 0, 3);

    while (1)
    {
        int val;
        int u, v;

        printf("\n1 : 전체 행렬 출력\n2 : u와 v 인접한지 체크\n3 : Vertex u와 인접한 모든 Vertex 탐색\n4 : deg(u)\n5 : 종료\n숫자를 입력하세요 : ");
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