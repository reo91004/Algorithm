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

    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int cnt = 0, n, x1, y1, x2, y2; // 출발점, 도착점
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cin >> n;

        for (int k = 0; k < n; ++k) {
            int x, y, r;
            std::cin >> x >> y >> r;

            // 출발점과 행성계 거리, 도착점과 행성계 거리
            int dist1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
            int dist2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
            int radius = r * r;

            // 출발점 - 행성계 거리가 radius보다 크고, 도착점 - 행성계 거리가 radius보다 크면 경유할 의미가 없음. 둘 중 하나만 크면 경유함
            if (dist1 < radius && dist2 < radius)
                continue;
            else if (dist1 < radius || dist2 < radius)
                cnt++;
        }

        std::cout << cnt << "\n";
    }

    return 0;
}