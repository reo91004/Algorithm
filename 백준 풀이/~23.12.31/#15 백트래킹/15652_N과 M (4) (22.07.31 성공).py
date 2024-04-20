import sys
input = sys.stdin.readline

def dfs(N, M, start):
    if M == len(res):
        print(' '.join(map(str, res)))
        return
    
    for i in range(start, N + 1):
        res.append(i)
        dfs(N, M, i)
        res.pop()

N, M = map(int, input().split())
res = []

dfs(N, M, 1)