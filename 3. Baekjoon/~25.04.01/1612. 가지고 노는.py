import sys

input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())
    i = 11
    num = 2

    if N == 1:
        print(1)
    elif N % 2 == 0 or N % 5 == 0:
        print(-1)
    else:
        while i % N != 0:
            i = i % N
            i = i * 10 + 1
            num += 1
        print(num)
