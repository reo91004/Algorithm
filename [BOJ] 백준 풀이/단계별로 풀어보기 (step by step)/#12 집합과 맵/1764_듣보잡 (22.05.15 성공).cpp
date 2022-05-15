#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    std::map<std::string, int> mp;
    std::vector<std::string> v;
    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < N + M; ++i) {
        std::string str;
        std::cin >> str;
        mp[str]++;

        if (mp[str] > 1) 
            v.push_back(str);
    }

    sort(v.begin(), v.end());
    std::cout << v.size() << '\n';

    for (auto o : v) std::cout << o << '\n';

    return 0;
}