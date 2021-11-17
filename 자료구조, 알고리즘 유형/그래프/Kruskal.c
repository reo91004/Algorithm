#include <stdio.h>
#include <stdlib.h> // qsort를 활용하기 위한 헤더
#define MAX_VERTICES 5
#define INF 1000 // 무한대 뜻함

int graph[MAX_VERTICES][MAX_VERTICES] = { {0, INF, INF, 3, 12}, {INF, 0, 2, 5, INF}, {INF, 2, 0, 3, 7}, {3, 5, 3, 0, INF}, {12, INF, 7, INF, 0} };

typedef struct
{
    int key;
    int u;
    int v;
} Graph;

int compare(const void* a, const void* b) // qsort를 활용하기 위한 compare 함수
{
    Graph* m = (Graph*)a;
    Graph* n = (Graph*)b;
    if (m->key < n->key)
        return -1;
    if (m->key > n->key)
        return 1;
    return 0;
}

int parent[MAX_VERTICES]; // 부모 노드
int edge_num = 0;         // 간선의 개수

void init_set()
{
    for (int i = 0; i < MAX_VERTICES; i++)
        parent[i] = -1;
}
int find_set(int v)
{
    while (parent[v] >= 0)
        v = parent[v];

    return v;
}

void union_set(int n1, int  n2)
{
    n1 = find_set(n1); // 이는 정점의 부모를 찾는 것과도 같기 때문에 find_set을 써도 무방
    n2 = find_set(n2);
    if (n1 < n2)
        parent[n2] = n1;
    else
        parent[n1] = n2;
}
void kruskal(Graph g[], int n)
{
    int i, u, v;
    int k_edge_num = 0;                           
    qsort(g, edge_num, sizeof(Graph), compare); // 간선 가중치 정렬

    for (i = 0; k_edge_num < n - 1; ++i) // 간선의 수는 총 n-1개가 되어야 함
    {
        u = g[i].u;
        v = g[i].v;
        if (find_set(u) != find_set(v))
        {                      
            k_edge_num++;
            union_set(u, v);
            printf("간선 : %d - %d\n", u, v);
        }
    }
}

int main()
{
    Graph g[INF]; // 간선 집합

    init_set();

    for (int i = 0; i < MAX_VERTICES; i++) // 추가 작업
        for (int j = i; j < MAX_VERTICES; j++)
            if (graph[i][j] != INF && graph[i][j] != 0) // 간선이 연결되어있지 않고 같은 값이 아니면 연결작업
            {
                g[edge_num].key = graph[i][j];
                g[edge_num].u = i;
                g[edge_num].v = j;
                edge_num++;
            }

    kruskal(g, MAX_VERTICES);
}