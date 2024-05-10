#include <iostream>
#include <algorithm>

int arr[9][9];
int cnt = 0;

// 스도쿠 최종 모습 출력
void print() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) 
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }

    exit(0);
}

bool check(int x, int y, int val) {
    // 같은 행, 열에 같은 숫자가 있으면 불가능
    for (int i = 0; i < 9; ++i) {
        if (arr[x][i] == val) return false;
        if (arr[i][y] == val) return false;
    }

    // 3 x 3 정사각형 범위를 위한 변수 선언
    int start_x = (x / 3) * 3;
    int end_x = (x / 3) * 3 + 3;
    int start_y = (y / 3) * 3;
    int end_y = (y / 3) * 3 + 3;

    // 3 x 3 정사각형 안에 같은 값이 있으면 불가능
    for (int i = start_x; i < end_x; ++i) {
        for (int j = start_y; j < end_y; ++j)
            if (arr[i][j] == val) 
                return false;
    }

    return true;
}

void dfs(int x, int y, int cur) {
    if (cur == cnt) // 해결이 완료되었으면 최종 출력
        print();
    else if (y == 9) // 다음 줄로 넘어감
        dfs(x + 1, 0, cur);
    
    if (arr[x][y] == 0) {
        for (int i = 1; i <= 9; ++i) {
            if (check(x, y, i)) {
                arr[x][y] = i;
                dfs(x, y + 1, cur + 1);
                arr[x][y] = 0; // 혹여라도 이후에 잘못되었으면 복구해야 함
            }
        }
    }
    else
        dfs(x, y + 1, cur);
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
            std::cin >> arr[i][j];

            if (arr[i][j] == 0)
                cnt++;
        }

    dfs(0, 0, 0);

    return 0;
}