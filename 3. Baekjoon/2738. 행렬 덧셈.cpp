#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr1(N, vector<int>(M));
    vector<vector<int>> arr2(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr2[i][j];
        }
    }

    // 행렬 덧셈, 결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr1[i][j] + arr2[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}