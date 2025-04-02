if __name__ == "__main__":
    import sys

    input = sys.stdin.readline

    H, M = map(int, input().split())

    if M < 45:
        M = 60 - 45 + M  # M를 남은 시간으로 바꿈
        H = (H + 24 - 1) % 24  # H가 음수가 나오면 안되므로 mod 연산
        print(f"{H} {M}")
    else:
        print(f"{H} {M - 45}")
