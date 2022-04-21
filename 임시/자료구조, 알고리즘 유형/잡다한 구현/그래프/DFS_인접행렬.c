#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>

int visited[MAX];

typedef struct Graph // Graph에서 Adjacency Matrix 구현
{
    int num_vertices;
    int adj_matrix[MAX][MAX];
} Graph;

void init(Graph *g, int n);               // 그래프 초기화
void insert_edge(Graph *g, int v, int u, int num); // 그래프 엣지 인서트
int adjacent(Graph *g, int v, int u);     // Vertex u와 v 가 adjacent 한지 체크
void printGraph(Graph *g);                // 그래프 출력
void reset_visited(Graph *g);
void DFS(Graph *g, int v);

int main()
{
    Graph g;
    int n;

    printf("N*N 행렬의 행 크기를 입력하시오 (4 이상) : ");
    scanf("%d", &n);
    init(&g, n);

    insert_edge(&g, 0, 1, 4);
    insert_edge(&g, 0, 3, 3);
    insert_edge(&g, 0, 2, 5);
    insert_edge(&g, 1, 4, 6);
    insert_edge(&g, 1, 3, 2);
    insert_edge(&g, 2, 3, 1);

    DFS(&g, 0);
}

void init(Graph *g, int n) // 모두 0으로 초기화함
{
    g->num_vertices = n;
    int i, j;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            g->adj_matrix[i][j] = 0;
    }
}

void insert_edge(Graph *g, int v, int u, int num)
{
    g->adj_matrix[v][u] = num;
    g->adj_matrix[u][v] = num;
}

int adjacent(Graph *g, int v, int u) // Vertex u와 v 가 adjacent 한지 체크
{
    return g->adj_matrix[v][u];
}

void printGraph(Graph *g)
{
    for (int i = 0; i < g->num_vertices; i++)
    {
        for (int j = 0; j < g->num_vertices; j++)
            printf("%d ", g->adj_matrix[i][j]);

        printf("\n");
    }
}

void reset_visited(Graph *g)
{
    for (int i = 0; i < g->num_vertices; i++)
        visited[i] = 0;
}

void DFS(Graph *g, int v)
{
    int w;
    visited[v] = 1;
    printf("%d ", v);
    for (w = 0; w < g->num_vertices; w++)
        if (g->adj_matrix[v][w] != 0 && visited[w] == 0)
            DFS(g, w);
}