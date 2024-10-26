n, *rest = map(int, open(0).read().split())
s = rest[:n]
dp = [[0] * (n + 1) for _ in range(n + 1)]
S = 0
for i in range(n - 1, -1, -1):
    for j in range(n - 1, -1, -1):
        if s[i] <= s[j]:
            dp[i][j] = 1 + dp[i + 1][j + 1]
        else:
            dp[i][j] = 0
        S += dp[i][j]
print(S)
