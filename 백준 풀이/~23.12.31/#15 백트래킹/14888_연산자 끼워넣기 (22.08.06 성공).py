import sys
input = sys.stdin.readline

res_min = 1e9
res_max = -1e9

def dfs(cur, res):
    global res_min, res_max
    
    if cur == N:
        res_min = min(res_min, res)
        res_max = max(res_max, res)
        return
    
    for i in range(4):
        if operators[i] == 0:
            continue

        operators[i] -= 1

        if i == 0:
            dfs(cur + 1, res + arr[cur])
        elif i == 1:
            dfs(cur + 1, res - arr[cur])
        elif i == 2:
            dfs(cur + 1, res * arr[cur])
        elif i == 3:
            dfs(cur + 1, int(res / arr[cur]))
        
        operators[i] += 1

# 시작
N = int(input())
arr = list(map(int, input().split()))
operators = list(map(int, input().split()))

dfs(1, arr[0])

print(f"{res_max}\n{res_min}")
