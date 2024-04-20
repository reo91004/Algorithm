#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int var;
    std::cin >> var;

    if (var % 4 == 0 && (var % 100 != 0 || var % 400 == 0))
        std::cout << "1";
    else
        std::cout << "0";

    return 0;
}