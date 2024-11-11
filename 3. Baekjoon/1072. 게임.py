import sys

input = sys.stdin.readline


if __name__ == "__main__":
    X, Y = map(int, input().split())
    Z = int(100 * Y / X)

    start = 0
    end = X

    # 이진 탐색
    # '최소' 이므로, end를 현재 게임 횟수로 저장한다.
    # 또한 승률이 이미 99라면 승률이 절대 변하지 않는다.
    answer = -1
    while start <= end:
        middle = (start + end) // 2
        # 새로운 승률
        new_z = int(100 * (Y + middle) / (X + middle))

        # 새로운 승률이 더 높다면, 더 작은 횟수가 있을지 탐색한다.
        if new_z > Z:
            answer = middle
            end = middle - 1
        # 새로운 승률이 더 높지 않다면, 더 많은 횟수는 가능한지 탐색한다.
        else:
            start = middle + 1

    print(answer)
