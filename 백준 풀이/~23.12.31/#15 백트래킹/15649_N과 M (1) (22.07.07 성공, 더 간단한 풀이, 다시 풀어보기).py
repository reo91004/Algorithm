import sys
input = sys.stdin.readline

N, M = map(int, input().split())
res = []

def dfs(res):
    if M == len(res):
        print(' '.join(map(str, res)))
        return
    
    for i in range(1, N + 1):
        if i not in res:
            dfs(res + [i])

dfs(res)