#include <algorithm>
#include <iostream>

void init() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    std::string str;
    std::cin >> str;

    std::sort(str.begin(), str.end(), std::greater<int>());

    std::cout << str;
}