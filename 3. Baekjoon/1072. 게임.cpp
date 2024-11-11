#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;

    long long Z = Y * 100 / X;
    int start = 0;
    int end = X;

    // '최소' 승률을 찾기 위한 변수
    int answer = -1;
    while (start <= end) {
        // 중간값 계산
        long long middle = (start + end) / 2;

        // 새로운 승률 계산
        long long new_z = (100 * (Y + middle) / (X + middle));

        // 새로운 승률이 더 높다면, 더 작은 횟수가 있을지 탐색
        if (new_z > Z) {
            answer = middle;
            end = middle - 1;
        }
        // 새로운 승률이 더 높지 않다면, 더 많은 횟수를 탐색
        else {
            start = middle + 1;
        }
    }
    cout << answer << endl;
    return 0;
}