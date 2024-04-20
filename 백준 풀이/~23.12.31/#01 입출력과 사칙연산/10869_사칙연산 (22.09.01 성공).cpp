#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int A, B;
    std::cin >> A >> B;
    
    std::cout << A + B << "\n";
    std::cout << A - B << "\n";
    std::cout << A * B << "\n";

    if (B != 0)
        std::cout << A / B << "\n";

    std::cout << A % B << "\n"; 

    return 0;
}