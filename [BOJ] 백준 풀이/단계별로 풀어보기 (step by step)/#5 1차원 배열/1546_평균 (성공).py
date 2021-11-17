N = int(input())
arr = list(map(float, input().split()))
M = max(arr)
for i in range(N):
    arr[i] = arr[i] / M * 100

print(sum(arr) / N)
