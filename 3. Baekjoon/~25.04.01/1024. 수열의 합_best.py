import sys

input = sys.stdin.readline


def Solution(N, L):
    for length in range(L, 101):  # L부터 100까지만 검사
        start = (N - (length * (length - 1) // 2)) // length
        if start < 0:
            continue
        if start * length + (length * (length - 1) // 2) == N:
            return [start + i for i in range(length)]
    return -1


if __name__ == "__main__":
    N, L = map(int, input().split())

    result = Solution(N, L)

    if result == -1:
        print(-1)
    else:
        print(*result)
