#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    int var, sum = 0;

    std::cin >> var;

    for (int i = 1; i <= var; ++i)
        sum += i;

    std::cout << sum;

    return 0;
}