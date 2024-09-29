#include <iostream>
#include <utility>

using namespace std;

int main() {
    int N;
    int cnt = 1;
    pair<int, int> arr[50];
    cin >> N;

    for (int i = 0; i < N; ++i) 
        cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < N; ++i) {
        cnt = 1;

        for (int j = 0; j < N; j++)
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                cnt++;
        cout << cnt << " ";
    }

    return 0;
}