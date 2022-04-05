#include <iostream>

using namespace std;

int main() {
    int N;
    int ans = 0;
    int check = 0; // 봉지가 모두 채워지는지 체크
    cin >> N;

    while (N >= 0) {
        if (N % 5 == 0) {
            ans += (N / 5);
            check++;
            break;
        }
        N -= 3;
        ans++;
    }

    if (check == 1)
        cout << ans << "\n";
    else
        cout << -1 << "\n";
}