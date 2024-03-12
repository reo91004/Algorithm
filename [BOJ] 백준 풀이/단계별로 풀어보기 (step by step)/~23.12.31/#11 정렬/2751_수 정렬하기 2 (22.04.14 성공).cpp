#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i : v)
        cout << i << "\n";

    return 0;
}