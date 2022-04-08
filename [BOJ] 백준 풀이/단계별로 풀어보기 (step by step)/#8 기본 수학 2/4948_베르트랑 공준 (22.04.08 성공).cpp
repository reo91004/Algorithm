#include <iostream>
#include <algorithm>

using namespace std;

bool arr[246913];

void isPrime() {
    int i = 2;
    arr[0] = false;
    arr[1] = false;

    while (i <= 246912) {
        if (arr[i])
            for (int j = i + i; j <= 246912; j += i)
                if (arr[j])
                    arr[j] = false;
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    fill(arr, arr + 246913, true);
    isPrime();

    while (N) {
        int res = 0;

        for (int i = N + 1; i <= 2 * N; ++i)
            if (arr[i])
                res++;

        cout << res << "\n";

        cin >> N;
    }
    
    return 0;
}