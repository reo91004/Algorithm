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

    for (int i = 1; i < 10; ++i)
        std::cout << var << " * " << i << " = " << var * i << "\n";

    return 0;
}