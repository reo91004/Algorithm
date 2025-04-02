import sys
import math

input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())
    sizes = list(map(int, input().split()))
    T, P = map(int, input().split())

    count = sum(math.ceil(size / T) for size in sizes)

    print(count)
    print(N // P, N % P)
