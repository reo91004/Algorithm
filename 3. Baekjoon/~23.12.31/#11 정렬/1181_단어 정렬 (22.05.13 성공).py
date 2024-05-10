import sys
input = sys.stdin.readline

N = int(input())
arr = []

for i in range(N):
    arr.append(input().strip())

arr = set(arr)
arr = list(arr)
arr.sort()
arr.sort(key = len) # 상위 조건을 나중에 써줘야 함

for i in arr:
    print(i)