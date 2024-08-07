def zigzag_square(n: int) -> None:
    # n x n 크기의 2차원 배열 초기화
    square = [[0] * n for _ in range(n)]

    num = 1
    for diag in range(2 * n - 1):
        if diag % 2 == 0:
            # 대각선이 짝수일 때는 좌하향
            row = diag if diag < n else n - 1
            col = 0 if diag < n else diag - n + 1
            while row >= 0 and col < n:
                square[row][col] = num
                num += 1
                row -= 1
                col += 1
        else:
            # 대각선이 홀수일 때는 우상향
            col = diag if diag < n else n - 1
            row = 0 if diag < n else diag - n + 1
            while col >= 0 and row < n:
                square[row][col] = num
                num += 1
                col -= 1
                row += 1

    # 2차원 배열 출력
    for row in square:
        print(" ".join(map(str, row)))


# 테스트
zigzag_square(5)
