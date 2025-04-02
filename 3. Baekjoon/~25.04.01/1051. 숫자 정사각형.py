import sys

input = sys.stdin.readline

if __name__ == "__main__":
    """
    꼭짓점만 같으면 됨, count 수를 늘려 i + count 식만 확인하는 식으로.
    """
    # N : 행, M : 열
    N, M = map(int, input().split())
    result = 1

    # 정사각형 만들기
    arr = []
    for _ in range(N):
        number = input().rstrip()
        arr.append([int(digit) for digit in number])

    # 이제 구현
    # (0, 0)부터 (N-1, M-1)까지 정사각형 순환
    for i in range(N):
        for j in range(M):
            for count in range(1, min(N - i, M - j)):
                if (
                    arr[i][j]
                    == arr[i + count][j]
                    == arr[i][j + count]
                    == arr[i + count][j + count]
                ):
                    result = max(result, count + 1)

    print(result**2)  # 정사각형의 넓이 출력
