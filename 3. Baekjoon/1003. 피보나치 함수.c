#include <stdio.h>

void Solution(int N, int *zero_count, int *one_count) {
    static int dp[41] = {0, 1}; // 첫 두 개의 값만 초기화

    if (N == 0) {
        *zero_count = 1;
        *one_count = 0;
        return;
    } else if (N == 1) {
        *zero_count = 0;
        *one_count = 1;
        return;
    }

    for (int i = 2; i <= N; i++) {
        if (dp[i] == 0) { // 아직 계산되지 않은 경우
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    *zero_count = dp[N - 1];
    *one_count = dp[N];
}

int main() {
    int T, N;
    int zero_count, one_count;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        Solution(N, &zero_count, &one_count);
        printf("%d %d\n", zero_count, one_count);
    }

    return 0;
}