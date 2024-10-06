def Solution(N):
    # 0은 10의 개수에서 나오고 10은 2와 5에서 나오는데, 5가 더 적게 나오므로
    # 5의 개수만 구하면 됨
    if N < 0:
        return 0

    count = 0
    i = 5
    while N // i >= 1:  # 25, 125, 625등을 계산하기 위함 (5가 중복으로 더 들어가있음)
        count += N // i  # 5의 배수 계산 (5, 10, 15, 20, 25)
        i *= 5

    return count


if __name__ == "__main__":
    import sys

    input = sys.stdin.readline

    N = int(input())

    print(Solution(N))
