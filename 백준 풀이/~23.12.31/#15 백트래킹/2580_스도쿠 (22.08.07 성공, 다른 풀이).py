import sys
input = sys.stdin.readline

def print_all():
    for i in range(9):
        print(*arr[i])
        
    exit(0)

def check(x, y, cur):
    # 같은 행, 열에 같은 숫자가 있으면 불가능
    for i in range(9):
        if arr[x][i] == cur: return False
        if arr[i][y] == cur: return False

    # 3 x 3 정사각형 범위를 위한 변수 선언
    start_x = (x // 3) * 3
    end_x = (x // 3) * 3 + 3
    start_y = (y // 3) * 3
    end_y = (y // 3) * 3 + 3

    # 3 x 3 정사각형 안에 같은 값이 있으면 불가능
    for i in range(start_x, end_x):
        for j in range(start_y, end_y):
            if arr[i][j] == cur:
                return False

    return True

def dfs(cur):
    if cur == len(blank): # 해결이 완료되었으면 최종 출력
        print_all()

    x = blank[cur][0]
    y = blank[cur][1]

    for i in range(10):
        if check(x, y, i):
            arr[x][y] = i
            dfs(cur + 1)
            arr[x][y] = 0; # 혹여라도 이후에 잘못되었으면 복구해야 함
            
if __name__ == "__main__":
    blank = []
    arr = [0 for _ in range(9)]
    for i in range(9):
        arr[i] = list(map(int, input().split()))
        for j in range(9):
            if arr[i][j]==0:
                blank.append((i,j))

    dfs(0)