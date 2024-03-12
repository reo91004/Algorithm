#include <algorithm>
#include <iostream>
#include <vector>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int N;
    std::cin >> N;
    std::vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    for (int i = 1; i < N; ++i) {
        int cur = gcd(v[i], v[0]);
        std::cout << v[0] / cur << "/" << v[i] / cur << "\n";
    }

    return 0;
}