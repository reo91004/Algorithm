def count_paper(x, y, n):  # 재귀적으로 색종이 분할
    color = paper[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if paper[i][j] != color:  # 색종이가 같은 색이 아니라면 4등분 리턴
                n_2 = n // 2
                return [
                    sum(a)
                    for a in zip(
                        count_paper(x, y, n_2),
                        count_paper(x, y + n_2, n_2),
                        count_paper(x + n_2, y, n_2),
                        count_paper(x + n_2, y + n_2, n_2),
                    )
                ]
    return [1, 0] if color == 0 else [0, 1]  # 기저조건


if __name__ == "__main__":
    import sys

    N = int(sys.stdin.readline())
    paper = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

    white, blue = count_paper(0, 0, N)
    print(white)
    print(blue)
