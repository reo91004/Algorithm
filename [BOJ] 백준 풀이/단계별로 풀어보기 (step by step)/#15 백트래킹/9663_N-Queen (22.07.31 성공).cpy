import sys
input = sys.stdin.readline

def isPossible(val):
    for i in range(val):
        if res[i] == res[val] or abs(res[i] - res[val]) == val - i:
            return False

    return True

def dfs(val):
    global cnt

    if val == N:
        cnt += 1
        return
    else:
        for i in range(N):
            res[val] = i
            if isPossible(val):
                dfs(val + 1)

# 시작
N = int(input())
cnt = 0
res = [0] * N

dfs(0)
print(cnt)