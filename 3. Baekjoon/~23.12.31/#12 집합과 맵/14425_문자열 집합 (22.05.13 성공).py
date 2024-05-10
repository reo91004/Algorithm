import sys
input = sys.stdin.readline

cnt = 0
arr = []
N, M = map(int, input().split())

for i in range(N):
    arr.append(input())

for i in range(M):
    word = input()
    if word in arr:
        cnt += 1

print(cnt)