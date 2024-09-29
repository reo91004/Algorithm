def Solution(N):
    if N == 0:
        return 1, 0
    elif N == 1:
        return 0, 1
    else:
        dp = [0 for _ in range(N + 1)]
        dp[0] = 0
        dp[1] = 1

        for i in range(2, N + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[N - 1], dp[N]


if __name__ == "__main__":
    import sys

    T = int(sys.stdin.readline())

    for i in range(T):
        N = int(input())
        print(*Solution(N))
