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

    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    int res1 = std::min(x, y);
    int res2 = std::min(w - x, h - y);

    std::cout << std::min(res1, res2) << "\n";

    return 0;
}