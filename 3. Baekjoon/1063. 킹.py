import sys

input = sys.stdin.readline


def solution(king: list, stone: list, move: list) -> None:
    for _ in range(int(N)):
        m = input().rstrip()

        # 움직였을 경우의 위치 : dx, dy
        dx = king[0] + move[m][0]
        dy = king[1] + move[m][1]

        # 체스판 위에 존재
        if 0 < dx <= 8 and 0 < dy <= 8:
            # 킹이 돌 위에 올라감
            if dx == stone[0] and dy == stone[1]:
                sx = stone[0] + move[m][0]
                sy = stone[1] + move[m][1]
                # 돌도 체스판 위에 존재하면 둘 다 이동
                if 0 < sx <= 8 and 0 < sy <= 8:
                    king = [dx, dy]
                    stone = [sx, sy]
            else:
                king = [dx, dy]  # 킹만 이동

    print(f"{chr(king[0] + 64)}{king[1]}")
    print(f"{chr(stone[0] + 64)}{stone[1]}")


if __name__ == "__main__":
    king, stone, N = input().rstrip().split()

    king = list(map(int, [ord(king[0]) - 64, king[1]]))
    stone = list(map(int, [ord(stone[0]) - 64, stone[1]]))

    # 이동 딕셔너리 생성
    move = {
        "R": [1, 0],
        "L": [-1, 0],
        "B": [0, -1],
        "T": [0, 1],
        "RT": [1, 1],
        "LT": [-1, 1],
        "RB": [1, -1],
        "LB": [-1, -1],
    }

    solution(king, stone, move)
