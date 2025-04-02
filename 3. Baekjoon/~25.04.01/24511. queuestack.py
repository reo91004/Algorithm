from collections import deque
import sys

input = sys.stdin.readline


def Solution(N, A, B, M, C):
    queuestack = deque()

    # 초기 큐 상태 설정
    for i in range(N):
        if A[i] == 0:  # 큐인 경우에만 추가
            queuestack.appendleft(B[i])

    results = []
    for x in C:
        queuestack.append(x)
        results.append(queuestack.popleft())

    return results


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    M = int(input())
    C = list(map(int, input().split()))

    results = Solution(N, A, B, M, C)
    print(*results)
