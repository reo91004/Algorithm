import sys

input = sys.stdin.readline


def debug(D):
    for i in range(N):
        for j in range(M):
            print(D[i][j], end=" ")
        print()
    print()


def flip(x, y, D):
    for i in range(x, x + 3):
        for j in range(y, y + 3):
            D[i][j] = 1 - D[i][j]


if __name__ == "__main__":
    N, M = map(int, input().split())
    A = [list(map(int, list(input().strip()))) for _ in range(N)]
    B = [list(map(int, list(input().strip()))) for _ in range(N)]

    D = [[A[i][j] ^ B[i][j] for j in range(M)] for i in range(N)]
    # debug(D)
    cnt = 0

    for i in range(N - 2):
        for j in range(M - 2):
            if D[i][j]:
                flip(i, j, D)
                # debug(D)
                cnt += 1

    if any(D[i][j] for i in range(N) for j in range(M)):
        print(-1)
    else:
        print(cnt)
