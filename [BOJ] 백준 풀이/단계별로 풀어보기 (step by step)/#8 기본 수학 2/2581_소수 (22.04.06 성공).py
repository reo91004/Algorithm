M = int(input())
N = int(input())
arr = [False, False] + [True] * 9999
i = 2

# 에라토스테네스의 체
while i <= 10000:
    if arr[i]: # 지워나가는 과정
        for j in range(i + i, 10001, i):
            if arr[j]:
                arr[j] = False
    i += 1

res = 0
check = 0
min = 0
for i in range(M, N + 1):
    if arr[i]:
        res += i
        if check == 0:
            min = i
            check = 1

if check == 0:
    print("-1")
else:
    print(f"{res}\n{min}")