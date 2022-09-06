#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int x, y;
    std::cin >> x >> y;

    std::cout << (x > 0 ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3));

    return 0;
}