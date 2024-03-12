import sys
input = sys.stdin.readline

N = int(input())
res = 0

for i in range(1, N + 1):
    cnt = i

    while cnt >= 1:
        if cnt % 5 == 0:
            res += 1
            cnt //= 5
        else:
            break

print(res)