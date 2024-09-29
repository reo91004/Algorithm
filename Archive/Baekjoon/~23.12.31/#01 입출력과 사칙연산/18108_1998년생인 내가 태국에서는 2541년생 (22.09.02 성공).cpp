#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int var;
    std::cin >> var;
    std::cout << var - 543 << "\n";

    return 0;
}