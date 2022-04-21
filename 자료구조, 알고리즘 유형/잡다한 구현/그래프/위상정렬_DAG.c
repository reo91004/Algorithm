#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <stdlib.h>

int visited[MAX];
int ppvisit[MAX][MAX];
int count = 1;

typedef struct Graph // Graph에서 Adjacency Matrix 구현
{
    int num_vertices;
    int adj_matrix[MAX][MAX];
} Graph;

void init(Graph *g, int n);                        // 그래프 초기화
void insert_edge(Graph *g, int v, int u, int num); // 그래프 엣지 인서트
int adjacent(Graph *g, int v, int u);              // Vertex u와 v 가 adjacent 한지 체크
void printGraph(Graph *g);                         // 그래프 출력
void reset_visited(Graph *g);
void DFS(Graph *g, int v);
void previsit(Graph *g, int v);
void postvisit(Graph *g, int v);
void explore(Graph *g, int v);

int stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty()
{
    if (top < 0)
        return 1;
    else
        return 0;
}
int IsFull()
{
    if (top >= MAX_STACK_SIZE - 1)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if (IsFull() == 1)
        printf("스택이 가득 찼습니다.");
    else
        stack[++top] = value;
}

int pop()
{
    if (IsEmpty() == 1)
        printf("스택이 비었습니다.");
    else
        return stack[top--];
}

int main()
{
    Graph g;
    int n;

    init(&g, 6);

    insert_edge(&g, 1, 2, 1);
    insert_edge(&g, 2, 4, 1);
    insert_edge(&g, 3, 1, 1);
    insert_edge(&g, 3, 4, 1);
    insert_edge(&g, 5, 3, 1);

    explore(&g, 5);

    for (int i = 0; i < 5; i++)
        printf("%d ", pop());
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

void explore(Graph *g, int v)
{
    visited[v] = 1;
    previsit(g, v);
    for (int i = 0; i < g->num_vertices; i++)
        if (g->adj_matrix[v][i] != 0 && visited[i] == 0)
            explore(g, i);
    postvisit(g, v);
    push(v);
}

void previsit(Graph *g, int v)
{
    ppvisit[v][0] = count;
    count++;
}

void postvisit(Graph *g, int v)
{
    ppvisit[v][1] = count;
    count++;
}