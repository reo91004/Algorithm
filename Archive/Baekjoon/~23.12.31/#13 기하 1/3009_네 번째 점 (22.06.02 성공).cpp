#include <algorithm>
#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (x1 == x2)
        std::cout << x3 << " ";
    else if (x1 == x3)
        std::cout << x2 << " ";
    else
        std::cout << x1 << " ";

    if (y1 == y2)
        std::cout << y3;
    else if (y1 == y3)
        std::cout << y2;
    else
        std::cout << y1;

    return 0;
}