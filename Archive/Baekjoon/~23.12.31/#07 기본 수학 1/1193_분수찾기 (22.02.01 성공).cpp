#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 1, 23, 456, 78910 등 1씩 크기가 늘어나므로 어디에 속하는지 찾기 위함
    int val = 1;
    while (N > val) {
        N -= val;
        val++;
    }

    // 홀수 대각선에선 분자가 아래로 증가, 짝수 대각선에선 위로 증가
    if (val % 2 == 0)
        cout << N << '/' << val + 1 - N << "\n";
    else
        cout << val + 1 - N << '/' << N << "\n";
}