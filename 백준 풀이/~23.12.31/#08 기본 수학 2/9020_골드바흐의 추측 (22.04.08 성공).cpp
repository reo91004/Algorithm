#include <algorithm>
#include <iostream>

using namespace std;

bool arr[10001];

void isPrime() {
    int i = 2;
    arr[0] = false;
    arr[1] = false;
    

    while (i <= 10000) {
        if (arr[i])
            for (int j = i + i; j <= 10000; j += i)
                if (arr[j]) arr[j] = false;
        i++;
    }
}

// n / 2를 mid라고 했을 때, mid - k와 mid + k가 모두 소수인 것을 찾으면 된다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    fill(arr, arr + 10000, true);
    isPrime();

    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;

        int mid = n / 2;

        for (int k = 0; k < mid; ++k) {
            if (arr[mid - k] && arr[mid + k]) {
                cout << mid - k << " " << mid + k << "\n";
                break;
            }
        }
    }

    return 0;
}