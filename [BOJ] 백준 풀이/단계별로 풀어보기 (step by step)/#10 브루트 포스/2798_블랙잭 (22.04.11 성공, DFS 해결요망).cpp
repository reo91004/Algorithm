#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, res = 0;
    cin >> N >> M;

    vector<int> v(N);

    for (int i = 0; i < N; ++i) cin >> v[i];

    for (int i = 0; i < N - 2; ++i)
        for (int j = i + 1; j < N - 1; ++j)
            for (int k = j + 1; k < N; ++k) { 
                int tmp = v[i] + v[j] + v[k];

                if (tmp <= M && res < tmp)
                    res = tmp;
            }

    cout << res;

    return 0;
}