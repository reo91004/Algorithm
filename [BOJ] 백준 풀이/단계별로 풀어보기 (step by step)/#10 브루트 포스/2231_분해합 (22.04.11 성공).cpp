#include <iostream>
#include <vector>

using namespace std;

int solution(int N) {
    int val = N;

    // 처음에는 1,000,000일때, 그 아래일때 등등 case를 나누어서 하려고 삽질했다.
    // 10으로 나누면서 하는 것이 좋은 아이디어인 듯하다.
    while (N) {
        val = val + N % 10;
        N /= 10;
    }

    return val;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; ++i) {
        int val = solution(i);

        if (val == N) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << "0" << "\n";

    return 0;
}