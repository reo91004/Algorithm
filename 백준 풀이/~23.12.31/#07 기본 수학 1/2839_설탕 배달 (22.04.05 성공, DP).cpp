#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// DP 풀이
int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 5000);
    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= N; ++i)
        dp[i] = min(dp[i - 5] + 1, dp [i - 3] + 1);
    
    cout << (dp[N] >= 5000 ? -1 : dp[N]) << "\n"; // dp[7]일 시 5001로 설정되기 때문에 >=
}