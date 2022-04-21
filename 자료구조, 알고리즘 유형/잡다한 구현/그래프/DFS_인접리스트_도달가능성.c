#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>

int visited[MAX];
int ppvisit[MAX][MAX];
int count = 1;

typedef struct node
{
    int item;
    int weight;
    struct node* next;
} node;

typedef struct Graph
{
    int num_vertices;
    node* adj_list[MAX];
} Graph;

void init(Graph* g, int n);                        // 그래프 초기화
void insert_edge(Graph* g, int v, int u, int num); // 그래프 엣지 인서트
int adjacent(Graph* g, int v, int u);              // Vertex u와 v 가 adjacent 한지 체크
void printGraph(Graph* g);                         // 그래프 출력
void reset_visited(Graph* g);
void DFS(Graph* g, int v);
void previsit(Graph* g, int v);
void postvisit(Graph* g, int v);
void explore(Graph* g, int v);

int main()
{
    Graph g;
    int n;

    init(&g, 10);

    insert_edge(&g, 0, 1, 1);
    insert_edge(&g, 0, 2, 1);
    insert_edge(&g, 0, 3, 1);
    insert_edge(&g, 1, 5, 1);
    insert_edge(&g, 2, 5, 1);
    insert_edge(&g, 1, 4, 1);
    insert_edge(&g, 4, 8, 1);
    insert_edge(&g, 4, 9, 1);
    insert_edge(&g, 8, 9, 1);
    insert_edge(&g, 3, 6, 1);
    insert_edge(&g, 3, 7, 1);
    insert_edge(&g, 6, 7, 1);

    explore(&g, 0);

    printGraph(&g);
}

void init(Graph* g, int n)
{
    g->num_vertices = n;
    int i;

    for (int i = 0; i < n; i++)
        g->adj_list[i] = NULL;
}

void insert_edge(Graph* g, int v, int u, int num)
{
    node* vertex_v;
    node* vertex_u;

    vertex_v = (node*)malloc(sizeof(node));
    vertex_u = (node*)malloc(sizeof(node));

    vertex_v->item = v;
    vertex_v->weight = num;
    vertex_v->next = NULL;
    vertex_u->item = u;
    vertex_u->weight = num;
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

        printf("%d의 인접 리스트\n", i);
        printf("previsit : %d, posvisit : %d\n", ppvisit[i][0], ppvisit[i][1]);

        while (cur != NULL)
        {
            printf("%d, 가중치 : %d | ", cur->item, cur->weight);
            cur = cur->next;
        }

        printf("\n\n");
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

void DFS(Graph* g, int v)
{
    node* cur;
    visited[v] = 1;
    printf("%d ", v);
    for (cur = g->adj_list[v]; cur != NULL; cur = cur->next)
        if (visited[cur->item] == 0)
            DFS(g, cur->item);
}

void explore(Graph* g, int v)
{
    node* cur;
    visited[v] = 1;
    previsit(g, v);
    for (cur = g->adj_list[v]; cur != NULL; cur = cur->next)
        if (visited[cur->item] == 0)
            explore(g, cur->item);
    postvisit(g, v);
}

void previsit(Graph* g, int v)
{
    ppvisit[v][0] = count;
    count++;
}

void postvisit(Graph* g, int v)
{
    ppvisit[v][1] = count;
    count++;
}