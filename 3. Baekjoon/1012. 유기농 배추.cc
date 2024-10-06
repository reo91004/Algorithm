#include <stdio.h>
#include <string.h>

#define MAX 50

void dfs(int x, int y, int M, int N, int cabbage[MAX][MAX]) {
    if (x < 0 || x >= N || y < 0 || y >= M || cabbage[x][y] == 0)
        return;

    // 방문 처리
    cabbage[x][y] = 0;

    dfs(x - 1, y, M, N, cabbage);
    dfs(x + 1, y, M, N, cabbage);
    dfs(x, y - 1, M, N, cabbage);
    dfs(x, y + 1, M, N, cabbage);
}

int main() {
    int T, M, N, K;

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d %d %d", &M, &N, &K);

        int cabbage[MAX][MAX] = {0};

        for (int k = 0; k < K; ++k) {
            int x, y;
            scanf("%d %d", &x, &y);
            cabbage[y][x] = 1;
        }

        int count = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (cabbage[i][j] == 1) {
                    dfs(i, j, M, N, cabbage);
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }
    return 0;
}