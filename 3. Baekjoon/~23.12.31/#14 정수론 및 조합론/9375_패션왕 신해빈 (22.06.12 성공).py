import sys
from collections import Counter
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    arr = []
    res = 1

    for i in range(N):
        s1, s2 = input().split()
        arr.append(s2)
    
    arr = Counter(arr)

    for key in arr:
        res *= arr[key] + 1

    print(res - 1)