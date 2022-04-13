#include <iostream>
#define MAX 10000

using namespace std;

int arr[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, tmp;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        arr[tmp] += 1;
    }

    for (int i = 0; i < MAX + 1; ++i)
        for (int j = 0; j < arr[i]; ++j) 
            cout << i << "\n";

    return 0;
}