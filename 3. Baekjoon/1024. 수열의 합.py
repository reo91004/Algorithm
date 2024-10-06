import sys

input = sys.stdin.readline


def Solution(N, L):
    for i in range(L, 101):
        target = N // i
        if i % 2 == 0:  # i가 짝수일 시
            if (target + target + 1) * i // 2 == N:
                if target - (i // 2) + 1 < 0:
                    continue
                return [target + i for i in range(-(i // 2) + 1, i // 2 + 1)]
        else:
            if target * i == N:
                if target - (i // 2) < 0:
                    continue
                return [target + i for i in range(-(i // 2), i // 2 + 1)]

    return -1


if __name__ == "__main__":
    N, L = map(int, input().split())

    result = Solution(N, L)

    if result == -1:
        print(-1)
    else:
        print(*result)
