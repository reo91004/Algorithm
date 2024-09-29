#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(int arr[], int N) {
    int i, j;
    int temp;

    for (i = 0; i < N - 1; ++i)
        for (j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
}

int main() {
    int N;
    int* arr;
    cin >> N;

    if (N < 1 || N > 1000) 
        exit(1);

    arr = new int[N];

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    BubbleSort(arr, N);

    for (int i = 0; i < N; ++i)
        cout << arr[i] << "\n";

    delete arr;

    return 0;
}