#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    double A, B;
    std::cin >> A >> B;
    std::cout.precision(15);

    std::cout << A / B;

    return 0;
}