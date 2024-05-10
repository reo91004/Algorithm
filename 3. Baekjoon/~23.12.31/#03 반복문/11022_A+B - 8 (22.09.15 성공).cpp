#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    int var, x, y;

    std::cin >> var;

    for (int i = 1; i <= var; ++i) {
        std::cin >> x >> y;  // 반복될때마다 입력받음
        std::cout << "Case #" << i << ": " << x << " + " << y << " = " << x + y << "\n";
    }

    return 0;
}