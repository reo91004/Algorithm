# 1012. BFS

from collections import deque
import sys

input = sys.stdin.readline


def bfs(x, y):
    queue = deque([(x, y)])
    cabbage[x][y] = 0  # 방문 처리

    while queue:
        x, y = queue.popleft()

        # 방향 확인
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy

            # 밭의 범위 내이고 배추가 있는 곳이면 큐에 추가
            if 0 <= nx < N and 0 <= ny < M and cabbage[nx][ny] == 1:
                queue.append((nx, ny))
                cabbage[nx][ny] = 0  # 방문 처리


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
                    bfs(i, j)
                    count += 1

        print(count)
