#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> BoolArray;

int main() {
    int M, N;
    cin >> M >> N;

    // 에라토스테네스의 체 배열 초기화, 0과 1은 소수가 아니므로 기본값 false
    BoolArray arr(N + 1, true);
    arr[0] = arr[1] = false;

    for (int cnt = 2; cnt <= N; cnt++) {
        if (arr[cnt]) {
            for (int j = cnt + cnt; j <= N; j += cnt) {
                arr[j] = false;
            }
        }
    }

    // M부터 N까지의 소수를 출력
    for (int i = M; i <= N; i++) {
        if (arr[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}
