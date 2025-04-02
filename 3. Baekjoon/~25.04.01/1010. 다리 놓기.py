import sys
import math

input = sys.stdin.readline


if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N, M = map(int, input().split())
        # 조합 공식 이용
        print(math.comb(M, N))
