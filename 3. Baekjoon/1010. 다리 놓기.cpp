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

        // 조합 공식, 어차피 M이 N보다 크므로 기본값 설정
        for (int i = M; i > M - N; --i) {
            res = res * i;
            res = res / tmp++;
        }

        std::cout << res << "\n";
    }
    return 0;
}