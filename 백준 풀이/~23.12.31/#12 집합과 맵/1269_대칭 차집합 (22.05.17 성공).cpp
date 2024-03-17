#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int A, B, sum = 0;
    std::cin >> A >> B;

    std::map<int, int> mpA, mpB;

    for (int i = 0; i < A; ++i) {
        int tmp;
        std::cin >> tmp;
        mpA[tmp] = tmp;
    }
    
    for (int i = 0; i < B; ++i) {
        int tmp;
        std::cin >> tmp;
        mpB[tmp] = tmp;
    }

    for (auto it = mpA.begin(); it != mpA.end(); it++)
        if (!mpB[it->first])
            sum++;

    for (auto it = mpB.begin(); it != mpB.end(); it++)
        if (!mpA[it->first])
            sum++;

    std::cout << sum;
}