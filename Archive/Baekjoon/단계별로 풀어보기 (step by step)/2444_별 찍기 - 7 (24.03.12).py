import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    for i in range(1, N):
        for _ in range(N - i):
            print(" ", end="")
        print("*" * ((i * 2) - 1))

    for i in range(N, 0, -1):
        for _ in range(N - i):
            print(" ", end="")
        print("*" * ((i * 2) - 1))
