import sys
from collections import deque


# BFS 탐색 함수
def solution(v):
    visited = [False] * N  # 방문 여부를 저장하는 리스트
    queue = deque([[v, 0]])  # 큐에 시작 노드와 깊이(0)를 추가
    visited[v] = True  # 시작 노드는 방문 처리
    count = 0  # 친구의 수를 세는 변수

    while queue:
        current, depth = queue.popleft()

        # 깊이가 2 이상이면 더 이상 탐색하지 않음
        if depth >= 2:
            continue

        # 현재 노드의 모든 친구를 탐색
        for i in range(N):
            if not visited[i] and graph[current][i] == "Y":
                count += 1  # 친구 수 증가
                visited[i] = True  # 방문 처리
                queue.append([i, depth + 1])  # 다음 깊이로 큐에 추가

    return count


if __name__ == "__main__":
    N = int(sys.stdin.readline())
    graph = [list(sys.stdin.readline().strip()) for _ in range(N)]

    result = 0
    for i in range(N):
        result = max(result, solution(i))

    print(result)
