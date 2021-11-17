#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#define MAX_V 10000
using namespace std;
int v, e, visited[MAX_V + 1], x, y, r;
vector<vector<int>> scc;
vector<vector<int>> vt;
vector<vector<int>> rvt;
stack<int> st;
bool cmp(vector<int> x, vector<int> y)
{
    return x[0] < y[0];
}
void dfs(int v)
{
    visited[v] = true;
    for (int next : vt[v])
    {
        if (visited[next])
            continue;
        dfs(next);
    }
    st.push(v);
}
void func(int v, int c)
{
    visited[v] = true;
    scc[c].push_back(v);
    for (int next : rvt[v])
    {
        if (visited[next])
            continue;
        func(next, c);
    }
}
int main()
{
    scanf("%d%d", &v, &e);
    vt.resize(v + 1);
    rvt.resize(v + 1);
    for (int i = 0; i < e; i++)
    {
        scanf("%d%d", &x, &y);
        vt[x].push_back(y);
        rvt[y].push_back(x);
    }
    for (int i = 1; i <= v; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
    }
    memset(visited, 0, sizeof(visited));
    while (st.size())
    {
        int here = st.top();
        st.pop();
        if (visited[here])
            continue;
        scc.resize(++r);
        func(here, r - 1);
    }
    for (int i = 0; i < r; i++)
        sort(scc[i].begin(), scc[i].end());
    sort(scc.begin(), scc.end(), cmp);
    printf("%d\n", r);
    for (int i = 0; i < r; i++)
    {
        for (int x : scc[i])
            printf("%d ", x);
        printf("-1\n");
    }
    return 0;
}