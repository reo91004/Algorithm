#include <algorithm>
#include <iostream>
#include <vector>

int N, cnt = 0;

bool isPossible(std::vector<int> &v, int row) {
    for (int i = 0; i < row; ++i) {
        // 일차원 배열에서 같은 위치에 있으면 안됨, 대각선상에 있으면 안됨
        if (v[i] == v[row] || abs(v[i] - v[row]) == row - i) return false;
    }
//col[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
    return true;
}

void dfs(std::vector<int> &v, int N, int row) {
    if (row == N)
        cnt++;
    else {
        for (int i = 0; i < N; ++i) {
            v[row] = i; // 현재 행 위치에 열 값을 할당한다.
            // 해당 행, 열에 존재할 수 있다면 다음 행을 검사한다.
            if (isPossible(v, row)) dfs(v, N, row + 1);
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

    std::cin >> N;
    
    std::vector<int> v(N);

    // v 벡터, N, 백트래킹을 시작할 위치 0을 넣는다.
    dfs(v, N, 0);

    std::cout << cnt << "\n";

    return 0;
}