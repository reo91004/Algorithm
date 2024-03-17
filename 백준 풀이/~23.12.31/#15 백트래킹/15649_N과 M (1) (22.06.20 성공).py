import sys
input = sys.stdin.readline

def dfs(res, visited, N, M, val):
    if M + 1 == val:
        print(' '.join(map(str, res)))
        return
    
    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = True
            res.append(i)
            dfs(res, visited, N, M, val + 1)
            visited[i] = False
            res.pop()

N, M = map(int, input().split())
visited = [False] * 9
res = []

dfs(res, visited, N, M, 1)