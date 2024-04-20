import sys
input = sys.stdin.readline

N = int(input())

# 동적 계획법
arr = [0] * 41
arr[2] = arr[1] = 1
for i in range(3, 41):
    arr[i] = arr[i - 1] + arr[i - 2]

print(f"{arr[N]} {N - 2}")