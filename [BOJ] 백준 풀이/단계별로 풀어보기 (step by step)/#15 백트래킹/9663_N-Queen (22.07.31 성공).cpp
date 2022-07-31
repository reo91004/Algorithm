#include <algorithm>
#include <iostream>
#include <vector>

int N, cnt = 0;

bool isPossible(std::vector<int> &v, int val) {
    for (int i = 0; i < val; ++i) {
        // 일차원 배열에서 같은 위치에 있으면 안됨, 대각선상에 있으면 안됨
        if (v[i] == v[val] || abs(v[i] - v[val]) == val - i) return false;
    }

    return true;
}

void dfs(std::vector<int> &v, int N, int val) {
    if (val == N)
        cnt++;
    else {
        for (int i = 0; i < N; ++i) {
            v[val] = i;
            if (isPossible(v, val)) dfs(v, N, val + 1);
        }
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
    
    std::vector<int> v(N);

    // v 벡터, N, 백트래킹을 시작할 위치 0을 넣는다.
    dfs(v, N, 0);

    std::cout << cnt << "\n";

    return 0;
}