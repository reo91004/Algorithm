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

    int a, b;
    std::cin >> a >> b;

    while (a != 0 && b != 0) {
        if (b % a == 0) // 약수일 때
            std::cout << "factor" << "\n";
        else if (a % b == 0) // 배수일 때
            std::cout << "multiple" << "\n";
        else
            std::cout << "neither" << "\n";
            
        std::cin >> a >> b;
    }

    return 0;
}