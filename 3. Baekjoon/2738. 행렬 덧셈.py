import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())

    # 배열 선언
    arr1, arr2 = [], []
    for _ in range(N):
        arr1.append(list(map(int, input().split())))
    for _ in range(N):
        arr2.append(list(map(int, input().split())))

    # 행렬 덧셈
    result = []
    for i in range(N):
        row = []
        for j in range(M):
            row.append(arr1[i][j] + arr2[i][j])
        result.append(row)

    # 결과 출력
    for row in result:
        print(*row)
