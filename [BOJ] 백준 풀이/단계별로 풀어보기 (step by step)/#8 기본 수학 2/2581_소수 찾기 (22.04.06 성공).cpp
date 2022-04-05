#include <cmath>
#include <iostream>

using namespace std;

// 원래는 루프를 2부터 나누어 n-1까지의 수 중 나머지가 0이 되는 수가 존재하는지
// 판별해야 함. 하지만 너무 비효율적이기 때문에 루프 횟수를 줄여야 함.
// 제곱근까지만 반복해도 가능하다고 알려져 있음.
bool isPrime(int val) {
    if (val < 2)
        return false;
    else {
        for (int i = 2; i <= sqrt(val); ++i) {
            if (val % i == 0) return false;
        }
    }
    return true;
}

int main() {
    int M, N, check = 0, res = 0, min;
    cin >> M >> N;

    for (int i = M; i <= N; ++i) {
        if (isPrime(i)) {
            res += i;

            if (check == 0) { // 최솟값을 저장하기 위함
                min = i;
                check++;
            }
        }
    }

    if (check == 0) // 소수가 아예 존재하지 않음
        cout << -1 << "\n";
    else
        cout << res << "\n" << min << "\n";
}