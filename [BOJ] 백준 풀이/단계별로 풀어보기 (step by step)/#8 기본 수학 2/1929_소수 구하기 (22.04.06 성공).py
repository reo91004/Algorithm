M, N = map(int, input().split())
arr = [False, False] + [True] * (N - 1)
i = 2

# 에라토스테네스의 체
while i <= N:
    if arr[i]: # 지워나가는 과정
        for j in range(i + i, N + 1, i):
            if arr[j]:
                arr[j] = False
    i += 1

for i in range(M, N + 1):
    if arr[i]:
        print(i)