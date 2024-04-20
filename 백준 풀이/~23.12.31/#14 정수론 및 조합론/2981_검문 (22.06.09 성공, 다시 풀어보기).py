import sys
import math
input = sys.stdin.readline

N = int(input())
arr = []
res = []

for _ in range(N):
    arr.append(int(input()))

arr.sort()

cur = arr[1] - arr[0]

for i in range(2, N):
    cur = math.gcd(cur, arr[i] - arr[i - 1])

for i in range(2, int(math.sqrt(cur)) + 1):
    if cur % i == 0:
        res.append(i)
        res.append(cur // i)

res.append(cur)
res = list(set(res))
res.sort()

print(*res)
