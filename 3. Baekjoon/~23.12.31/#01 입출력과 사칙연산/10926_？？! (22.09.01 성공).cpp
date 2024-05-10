#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    std::string var;
    std::cin >> var;
    std::cout << var << "??!" << "\n";

    return 0;
}