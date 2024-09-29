import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())
    res = [0] * N

    for _ in range(M):
        i, j, k = map(int, input().split())

        for x in range(i - 1, j):
            res[x] = k

    print(*res)
