#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int N, M;  // 포켓몬의 개수, 맞춰야 하는 문제 개수
    std::cin >> N >> M;
    std::map<std::string, int> mp;
    std::vector<std::string> v(N + 1); // 문자열을 출력하기 위함

    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        mp.insert(make_pair(str, i + 1));
        v[i + 1] = str;
    }

    for (int i = 0; i < M; ++i) {
        std::string str;
        std::cin >> str;

        if (isdigit(str[0])) {
            int key = stoi(str);
            std::cout << v[key] << "\n";
        }

        else
            std::cout << mp.find(str)->second << "\n";
    }

    return 0;
}