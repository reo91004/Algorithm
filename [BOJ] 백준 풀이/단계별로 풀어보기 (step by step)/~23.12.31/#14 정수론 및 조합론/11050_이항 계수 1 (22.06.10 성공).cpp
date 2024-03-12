#include <algorithm>
#include <iostream>
#include <vector>

int Factorial(int N) {
    if (N <= 1)
        return 1;
    else
        return N * Factorial(N - 1);
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int N, K;
    std::cin >> N >> K;

    std::cout << Factorial(N) / (Factorial(K) * Factorial(N - K));

    return 0;
}