#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// 3x3 영역을 뒤집는 함수
void flip(vvi &D, int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            D[i][j] = 1 - D[i][j];
        }
    }
}

int main() {
    init();

    int N, M;
    cin >> N >> M;

    vvi A(N, vi(M));
    vvi B(N, vi(M));

    // 행렬 A 입력
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            A[i][j] = line[j] - '0';
        }
    }

    // 행렬 B 입력
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            B[i][j] = line[j] - '0';
        }
    }

    // 차이 행렬 D 생성
    vvi D(N, vi(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            D[i][j] = A[i][j] ^ B[i][j];
        }
    }

    int cnt = 0;

    // 3x3 연산 적용
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 3; j++) {
            if (D[i][j] == 1) {
                flip(D, i, j);
                cnt++;
            }
        }
    }

    // 모든 원소가 0인지 확인
    bool possible = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (D[i][j] != 0) {
                possible = false;
                break;
            }
        }
        if (!possible)
            break;
    }

    // 결과 출력
    if (possible) {
        cout << cnt << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}