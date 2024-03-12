#include <algorithm>
#include <iostream>
#include <vector>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int A, B;
        std::cin >> A >> B;

        std::cout << lcm(A, B) << "\n";
    }
}