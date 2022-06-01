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
    std::vector<int> tmp(N);

    for (int i = 0; i < N; ++i) 
        std::cin >> v[i];

    tmp = v;
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    // find 함수 쓰면 시간초과
    for (int i = 0; i < v.size(); ++i) 
        std::cout << std::lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin() << " ";

    return 0;
}