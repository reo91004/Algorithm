#include <algorithm>
#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M, res = 1, tmp = 1;
        std::cin >> N >> M;

        for (int i = M; i > M - N; --i) {
            res = res * i;
            res = res / tmp++;
        }

        std::cout << res << "\n";
    }
    return 0;
}