import sys
input = sys.stdin.readline

def dfs(cur, idx):
    global res

    # cur이 N // 2와 같다면 한 팀에 총 인원의 반이 담겨졌다는 의미이므로 멈추고 능력치의 차이를 계산함.
    if cur == N // 2:
        res1, res2 = 0, 0
        for i in range(N):
            for j in range(N):
                # visited[i]가 true인 사람과 false인 사람으로 나눠지므로 능력치를 더하면 됨.
                if visited[i] and visited[j]:
                    res1 += arr[i][j]
                elif not visited[i] and not visited[j]:
                    res2 += arr[i][j]

        res = min(res, abs(res1 - res2))
        return

    # idx부터 탐색, 만약 i가 방문하지 않았다면 아무런 팀에 담겨있지 않다는 뜻이므로 i + 1인자를 넘겨줘 다음 사람부터 탐색하도록 함.
    for i in range(idx, N):
        if not visited[i]:
            visited[i] = True
            dfs(cur + 1, i + 1)
            visited[i] = False
            
if __name__ == "__main__":
    res = 201
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    visited = [False] * N

    dfs(0, 0)

    print(res)
