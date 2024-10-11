#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> S, int n) {
    int A = 0, B = 0;

    // A와 B 찾기
    for (int s : S) {
        if (s <= n) {
            A = s;
        }
        if (s >= n) {
            B = s;
            break;
        }
    }

    // 만약 A와 B가 같으면 (n이 범위에 포함된 경우) 0을 반환
    if (A == n || B == n) {
        return 0;
    }

    return (n - A) * (B - n) - 1;
}

int main() {
    int L;
    cin >> L;

    vector<int> S(L);
    for (int i = 0; i < L; i++) {
        cin >> S[i];
    }

    int n;
    cin >> n;

    sort(S.begin(), S.end());

    cout << solution(S, n) << endl;

    return 0;
}
