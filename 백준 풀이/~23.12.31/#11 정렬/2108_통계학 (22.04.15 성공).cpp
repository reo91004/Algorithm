#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, sum = 0, cntmax = 0, val = 0;
    cin >> N;
    vector<int> v(N); // 값을 저장할 벡터
    vector<int> cnt(8001); // 최빈값을 계산할 벡터

    for (int i = 0; i < N; ++i)  {
        cin >> v[i];
        sum += v[i]; // 총합 계산

        cnt[v[i] + 4000]++; // 최빈값 저장
    }

    sort(v.begin(), v.end());

    // 최빈값 중 가장 작은 값
    for (int i = 0; i <= 8000; ++i) {
        if (cnt[i] > cntmax) {
            cntmax = cnt[i];
            val = i;
        }
    }

    // 두 번째로 작은 최빈값을 구해야 한다.
    // 이미 위에서 가장 작은 최빈값을 찾아놨으므로 val + 1부터 탐색한다.
    for (int i = val + 1; i <= 8000; ++i) {
        if (cnt[i] == cntmax) {
            val = i;
            break;
        }
    }
    sum = round(double(sum) / N);

    cout << sum << "\n"; // 산술평균, round(double(sum) / N)을 그대로 쓰면 -0으로 출력됨
    cout << v[(N - 1) / 2] << "\n"; // 중앙값
    cout << val - 4000 << "\n"; // 최빈값
    cout << v[N - 1] - v[0]; // 최대 최소 차이
}