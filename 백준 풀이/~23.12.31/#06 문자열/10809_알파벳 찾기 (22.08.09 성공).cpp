#include <iostream>
#include <string>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    std::string text;
    std::string alp = "abcdefghijklmnopqrstuvwxyz";

    std::cin >> text;

    for(int i = 0; i < alp.length(); ++i)
        std::cout << (int)text.find(alp[i]) << " ";

    return 0;
}