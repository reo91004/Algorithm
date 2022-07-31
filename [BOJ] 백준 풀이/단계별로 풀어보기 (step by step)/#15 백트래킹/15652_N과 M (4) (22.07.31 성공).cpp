#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<int> &v, int N, int M, int val) {
    if (val == M + 1) {
        for (int i = 1; i <= M; ++i) std::cout << v[i] << " ";

        std::cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (v[val - 1] <= i) {
            v[val] = i;
            dfs(v, N, M, val + 1);
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

    int N, M;
    std::cin >> N >> M;

    std::vector<int> v(M + 1);

    dfs(v, N, M, 1);

    return 0;
}