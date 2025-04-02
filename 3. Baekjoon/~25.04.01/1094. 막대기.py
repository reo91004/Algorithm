import sys

input = sys.stdin.readline

if __name__ == "__main__":
    X = int(input())
    result = 0
    N = 64

    while X > 0:
        # 아직 막대기가 더 길면 반으로
        if N > X:
            N = N // 2
        else:
            result += 1
            X -= N

    print(result)

# 23 = 16 + 4 + 2 + 1
# 32 = 32
# 64 = 64
# 48 = 32 + 16
