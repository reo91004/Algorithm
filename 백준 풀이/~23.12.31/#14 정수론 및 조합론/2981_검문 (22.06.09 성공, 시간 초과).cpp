#include <algorithm>
#include <iostream>
#include <vector>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void print_divisor(int cur) {
    for (int i = 2; i <= cur; ++i) {
        if (cur % i == 0) {
            std::cout << i << " ";
        }
    }
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

    std::sort(v.begin(), v.end());

    int cur = v[1] - v[0];

    for (int i = 2; i < N; ++i) {
        cur = gcd(cur, v[i] - v[i - 1]);
    }

    print_divisor(cur);

    return 0;
}