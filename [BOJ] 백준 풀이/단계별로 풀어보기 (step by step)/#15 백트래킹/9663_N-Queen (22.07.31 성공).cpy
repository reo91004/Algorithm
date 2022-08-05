import sys
input = sys.stdin.readline

def isPossible(row):
    for i in range(row):
        if res[i] == res[row] or abs(res[i] - res[row]) == row - i:
            return False

    return True

def dfs(row):
    global cnt

    if row == N:
        cnt += 1
        return
    else:
        for i in range(N):
            res[row] = i
            if isPossible(row):
                dfs(row + 1)

# 시작
N = int(input())
cnt = 0
res = [0] * N

dfs(0)
print(cnt)