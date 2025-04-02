import sys
import math


def Solution(N, K):
    print(math.comb(N, K))


if __name__ == "__main__":
    input = sys.stdin.readline
    N, K = map(int, input().split())
    Solution(N, K)
