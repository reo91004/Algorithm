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

    int N;
    std::cin >> N;
    std::vector<int> v(N);

    for (int i = 0; i < N; ++i)
        std::cin >> v[i];

    int res = *std::max_element(v.begin(), v.end()) * *std::min_element(v.begin(), v.end());

    std::cout << res << "\n";

    return 0;
}