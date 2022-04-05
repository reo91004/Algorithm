N = int(input())
arr = [False, False] + [True] * 999
i = 2

# 에라토스테네스의 체
while i <= 1000:
    if arr[i]: # 지워나가는 과정
        for j in range(i + i, 1001, i):
            if arr[j]:
                arr[j] = False
    i += 1

cnt = 0
for i in map(int, input().split()):
    if arr[i]:
        cnt += 1

print(cnt)