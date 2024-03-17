#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> temp_v(v);
    sort(temp_v.begin(), temp_v.end());

    temp_v.erase(unique(temp_v.begin(), temp_v.end()), temp_v.end());

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(temp_v.begin(), temp_v.end(), v[i]);
        cout << it - temp_v.begin() << ' ';
    }

    return 0;
}