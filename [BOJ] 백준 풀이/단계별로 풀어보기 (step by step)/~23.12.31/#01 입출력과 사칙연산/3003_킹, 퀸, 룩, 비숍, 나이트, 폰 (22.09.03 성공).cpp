#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int chess[6] = {1, 1, 2, 2, 2, 8};
    std::vector<int> var(6);

    for (int i = 0; i < 6; ++i) {
        std::cin >> var[i];
        std::cout << chess[i] - var[i] << " ";
    }

    return 0;
}