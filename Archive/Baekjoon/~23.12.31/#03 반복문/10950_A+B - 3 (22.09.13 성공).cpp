#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int var, a, b;

    std::cin >> var;

    for (int i = 0; i < var; ++i) {
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }
    
    return 0;
}