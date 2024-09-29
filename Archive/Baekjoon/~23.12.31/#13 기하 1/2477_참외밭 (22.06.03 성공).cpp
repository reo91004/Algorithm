#include <algorithm>
#include <iostream>
#include <vector>

class pair {
  public:
    int point;
    int length;
};

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    std::vector<pair> v(6);
    int point[5] = {0};
    int big = 1, small = 1;

    int K; // 참외 개수
    std::cin >> K;

    for (int i = 0; i < 6; ++i) {
        std::cin >> v[i].point >> v[i].length;
        point[v[i].point]++;
    }

    for (int i = 0; i < 6; ++i) {
        if (point[v[i].point] == 1) { // 한 번씩 나온 부분은 가장 큰 사각형 넓이
            big = big * v[i].length;
        }
        else { // 현재 요소와 두번 뒤 요소의 point가 같으면 그 사이 length가 작은 사각형 요소
            if (v[i].point == v[(i + 2) % 6].point)
                small = small * v[(i + 1) % 6].length;
        }
    }

    std::cout << K * (big - small);

    return 0;
}