arr = [False, False] + [True] * (246912 - 1)
i = 2

# 에라토스테네스의 체
while i <= 246912:
    if arr[i]: # 지워나가는 과정
        for j in range(i + i, 246912 + 1, i):
            if arr[j]:
                arr[j] = False
    i += 1

while True:
    N = int(input())
    if (N == 0):
        break
    res = 0

    for i in range(N + 1, 2 * N + 1):
        if (arr[i]):
            res += 1
    
    print(res)