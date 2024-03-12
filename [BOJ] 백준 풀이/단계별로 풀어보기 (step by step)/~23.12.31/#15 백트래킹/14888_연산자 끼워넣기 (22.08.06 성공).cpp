#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

int N;
int arr[12];
int operators[4];  // 덧셈, 뺄셈, 곱셈, 나눗셈
int res_min = INT_MAX;
int res_max = INT_MIN;

void dfs(int cur, int res) {
    if (cur == N) {
        res_min = std::min(res_min, res);
        res_max = std::max(res_max, res);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operators[i] == 0)
            continue;

        operators[i]--;

        if (i == 0)
            dfs(cur + 1, res + arr[cur]);
        else if (i == 1)
            dfs(cur + 1, res - arr[cur]);
        else if (i == 2)
            dfs(cur + 1, res * arr[cur]);
        else if (i == 3)
            dfs(cur + 1, res / arr[cur]);
        
        operators[i]++;
    }
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    std::cin >> N;

    for (int i = 0; i < N; ++i) 
        std::cin >> arr[i];
    for (int i = 0; i < 4; ++i) 
        std::cin >> operators[i];

    dfs(1, arr[0]);

    std::cout << res_max << "\n" << res_min;

    return 0;
}