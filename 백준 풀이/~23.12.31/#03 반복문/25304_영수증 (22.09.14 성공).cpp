#include <iostream>
#include <vector>
#include <algorithm>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int X, N, a, b, res = 0;
    std::cin >> X >> N;

    for (int i = 0; i < N; ++i) {
        std::cin >> a >> b;
        res += a * b;
    }

    std::cout << ((X == res) ? "Yes" : "No");

    return 0;
}