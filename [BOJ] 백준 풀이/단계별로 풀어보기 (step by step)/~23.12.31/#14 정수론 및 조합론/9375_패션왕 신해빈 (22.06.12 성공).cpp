#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int T;
    std::cin >> T;

    std::map<std::string, int> mp;

    for (int t = 0; t < T; ++t) {
        int N, res = 1;
        std::string s1, s2;
        std::cin >> N;

        for (int i = 0; i < N; ++i) {
            std::cin >> s1 >> s2;

            mp[s2]++;
        }

        for (auto it : mp) {
            res = res * (it.second + 1);
        }

        std::cout << res - 1 << "\n";

        mp.clear();
    }

    return 0;
}