#include <algorithm>
#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int x, y, z;
    std::cin >> x >> y >> z;

    while (x && y && z) {
        if (x > y)
            std::swap(x, y);
        if (y > z)
            std::swap(y, z);
        
        if (z * z == x * x + y * y)
            std::cout << "right\n";
        else
            std::cout << "wrong\n";
        
        std::cin >> x >> y >> z;
    }

    return 0;
}