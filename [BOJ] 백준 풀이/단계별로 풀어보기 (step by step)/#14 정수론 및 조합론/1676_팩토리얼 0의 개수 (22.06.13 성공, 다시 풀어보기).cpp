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

    int N, res = 0;
    std::cin >> N;

    for (int i = 1; i <= N; ++i) {
        int cnt = i;
        
        while (cnt >= 1) {
            if (cnt % 5 == 0) {
                res++;
                cnt /= 5;
            }
            else
                break;
        }
    }

    std::cout << res;

    return 0;
}