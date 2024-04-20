#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int N, M, cnt = 0;
    std::cin >> N >> M;
    std::set<std::string> _set;

    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        _set.insert(str);
    }

    for (int i = 0; i < M; ++i) {
        std::string str;
        std::cin >> str;

        if (_set.find(str) != _set.end()) cnt++;
    }

    std::cout << cnt;

    return 0;
}