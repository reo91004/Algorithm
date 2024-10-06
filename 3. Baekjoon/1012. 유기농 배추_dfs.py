# 1012. DFS

import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline


def dfs(x, y):
    # 밭의 범위를 벗어나거나 배추가 없는 곳이면 종료
    if x < 0 or x >= N or y < 0 or y >= M or cabbage[x][y] == 0:
        return

    # 방문 처리
    cabbage[x][y] = 0

    # 인접한 배추 탐색
    dfs(x - 1, y)
    dfs(x + 1, y)
    dfs(x, y - 1)
    dfs(x, y + 1)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        # 가로길이, 세로길이, 배추가 심어진 위치 개수
        M, N, K = map(int, input().split())
        cabbage = [[0 for _ in range(M)] for _ in range(N)]

        for _ in range(K):
            X, Y = map(int, input().split())
            cabbage[Y][X] = 1

        count = 0
        for i in range(N):
            for j in range(M):
                if cabbage[i][j] == 1:
                    dfs(i, j)
                    count += 1

        print(count)
