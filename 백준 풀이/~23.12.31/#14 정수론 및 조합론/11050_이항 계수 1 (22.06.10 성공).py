import sys
import math
input = sys.stdin.readline

N, K = map(int, input().split())

print(math.comb(N, K))
