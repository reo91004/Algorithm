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

    std::string str, tmp;
    std::cin >> str;
    std::set<std::string> _set;

    for (int i = 0; i < str.length(); ++i) {
        tmp = "";
        for (int j = i; j < str.length(); ++j) {
            tmp += str[j];
            _set.insert(tmp);
        }
    }

    std::cout << _set.size();

    return 0;
}