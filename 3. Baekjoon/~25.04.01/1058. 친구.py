import sys
input = sys.stdin.readline

def solution(N, arr):
    result = 0
    for i in range(N):
        visited = [False] * N
        count = 0

        # 직접 친구 찾기
        for j in range(N):
            if arr[i][j]:
                visited[j] = True
                count += 1

        # 2-친구 찾기
        for j in range(N):
            if i != j and not visited[j]:  # 본인이 아니면서 아직 친구로 카운트되지 않은 경우
                # 공통 친구 k 찾기
                for k in range(N):
                    if arr[i][k] and arr[k][j]:  # i와 k가 친구이고, k와 j도 친구인 경우
                        count += 1
                        break  # 하나만 찾으면 충분하므로 즉시 종료

        result = max(result, count)

    return result

if __name__ == "__main__":
    N = int(input())
    arr = [
        [c == 'Y' for c in input().rstrip()]
        for _ in range(N)
    ]
    print(solution(N, arr))
