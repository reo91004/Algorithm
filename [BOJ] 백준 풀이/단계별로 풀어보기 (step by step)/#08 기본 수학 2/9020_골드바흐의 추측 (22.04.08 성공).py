arr = [False, False] + [True] * (10000 - 1)
i = 2

# 에라토스테네스의 체
while i <= 10000:
    if arr[i]: # 지워나가는 과정
        for j in range(i + i, 10000 + 1, i):
            if arr[j]:
                arr[j] = False
    i += 1

T = int(input())

while T:
    n = int(input())
    mid = n // 2

    for k in range(mid):
        if (arr[mid - k] and arr[mid + k]):
            print(f"{mid - k} {mid + k}")
            break

    T -= 1