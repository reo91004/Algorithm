import sys
import math

input = sys.stdin.readline

if __name__ == "__main__":
    N, W, H = map(int, input().split())

    for _ in range(N):
        val = int(input())

        if val <= (W**2 + H**2) ** 0.5:
            print("DA")
        else:
            print("NE")
