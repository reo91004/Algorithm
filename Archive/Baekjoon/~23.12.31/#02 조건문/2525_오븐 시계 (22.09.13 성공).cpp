#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int A, B, var;
    std::cin >> A >> B >> var;

    A = (A + (B + var) / 60) % 24;
    B = (B + var) % 60;

    std::cout << A << " " << B << "\n";

    return 0;
}