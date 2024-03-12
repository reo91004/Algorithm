import sys
input = sys.stdin.readline

def dfs(res, N, M, val):
    if M + 1 == val:
        print(' '.join(map(str, res)))
        return
    
    for i in range(1, N + 1):
        res.append(i)
        dfs(res, N, M, val + 1)
        res.pop()

N, M = map(int, input().split())
res = []

dfs(res, N, M, 1)