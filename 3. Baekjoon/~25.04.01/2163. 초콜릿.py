import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())
    print(N * M - 1)
