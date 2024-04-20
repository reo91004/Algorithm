import sys
input = sys.stdin.readline

def isPossible(row):
    for i in range(row):
        # 일차원 배열에서 같은 위치에 있으면 안됨, 대각선상에 있으면 안됨
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
            res[row] = i # 현재 행 위치에 열 값을 할당한다.
            # 해당 행, 열에 존재할 수 있다면 다음 행을 검사한다.
            if isPossible(row):
                dfs(row + 1)

# 시작
N = int(input())
cnt = 0
res = [0] * N

dfs(0)
print(cnt)