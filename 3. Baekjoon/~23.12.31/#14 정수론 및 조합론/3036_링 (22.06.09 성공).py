import sys
import math
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

for i in range(1, N):
    cur = math.gcd(arr[i], arr[0]);
    print(f"{arr[0] // cur}/{arr[i] // cur}")
