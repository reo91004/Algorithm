#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int A, B, C;
    std::cin >> A >> B >> C;

    std::cout << (A + B) % C << "\n";
    std::cout << ((A % C) + (B % C)) % C << "\n";
    std::cout << (A * B) % C << "\n";
    std::cout << ((A % C) * (B % C)) % C << "\n";

    return 0;
}