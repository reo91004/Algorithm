#include <stdio.h>
#define MAX_VERTICES 6 
#define INF 1000

int weight[MAX_VERTICES][MAX_VERTICES] = { {0, 4, 1, 3, INF, INF}, {4, 0, 4, 4, INF, INF}, {1, 4, 0, 2, INF, 4}, {3, 4, 2, 0, INF, 6}, {INF, INF, INF, INF, 0, 5}, {INF, INF, 4, 6, 5, 0} };

int visited[MAX_VERTICES];
int dist[MAX_VERTICES];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
}

int get_min_vertex(int n) // 가중치가 가장 적은 vertex 찾은 후 리턴, 예시에서 0에서 시작했으니 0이 나오고, 그 후 2가 나오는 식.
{
    int v;

    for (int i = 0; i < n; i++)
        if (visited[i] == 0) 
        {
            v = i;
            break;
        }

    for (int i = 0; i < n; i++)
        if (visited[i] == 0 && (dist[i] < dist[v]))
            v = i;

    return v;
}

void prim(int start, int n)
{
    init(n);

    dist[start] = 0; // 시작점은 0

    for (int i = 0; i < n; i++)
    {
        int u = get_min_vertex(n);
        visited[u] = 1;

        if (dist[u] == INF) return;

        printf("%d ", u);

        for (int v = 0; v < n; v++) // 주변 정점들의 가중치들을 갱신하는 작업
            if (weight[u][v] != INF)
                if (visited[v] == 0 && weight[u][v] < dist[v])
                    dist[v] = weight[u][v];
    }
}

void main()
{
    prim(0, MAX_VERTICES);
}