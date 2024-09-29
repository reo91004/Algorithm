#include <algorithm>
#include <iostream>
#include <vector>

int dp[1001][1001];

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int N, K;
    std::cin >> N >> K;

    dp[1][1] = 1;
    dp[1][0] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (j == 0 || i == j) {
                dp[i][j] = 1;
            } 
            else {
                // 매 연산마다 나눠주지 않으면 메모리 초과
                dp[i][j] = dp[i - 1][j - 1] % 10007 + dp[i - 1][j] % 10007;
            }
        }
    }
    
    std::cout << dp[N][K] % 10007;

    return 0;
}