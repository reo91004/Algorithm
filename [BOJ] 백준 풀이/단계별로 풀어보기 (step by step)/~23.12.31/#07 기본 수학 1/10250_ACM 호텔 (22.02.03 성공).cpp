#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, H, W, N;

    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> H >> W >> N; // 높이, 길이, 방 출력

        int floor = N % H; // 머무를 층
        int room = N / H + 1; // 머무를 방

        if (floor == 0) floor = H;
        if (N % H == 0) room -= 1;

        cout << floor * 100 + room << "\n";
    }
}