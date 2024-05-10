#include <iostream>
#include <vector>
#include <algorithm>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int a, b, c;
    std::cin >> a >> b >> c;

    if (a == b && b == c)
        std::cout << 10000 + (a * 1000);
    else if (a == b || a == c)
        std::cout << 1000 + (a * 100);
    else if (b == c)
        std::cout << 1000 + (b * 100);
    else
        std::cout << std::max(a, b, c) * 100;

    return 0;
}