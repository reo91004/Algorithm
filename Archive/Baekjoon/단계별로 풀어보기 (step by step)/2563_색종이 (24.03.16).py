import sys

sys = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    resArr = [[0] * 100 for _ in range(100)]

    for _ in range(N):
        x, y = map(int, input().split())

        for i in range(x, x + 10):
            for j in range(y, y + 10):
                resArr[i][j] = 1

    print(sum(sum(row) for row in resArr))
