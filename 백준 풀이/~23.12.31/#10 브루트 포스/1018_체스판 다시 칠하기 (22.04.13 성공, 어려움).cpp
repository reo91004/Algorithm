#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

char arr[50][50];

int solution(int x, int y) {
    int cnt = 0;

    for (int i = x; i < x + 8; ++i)
        for (int j = y; j < y + 8; ++j)
            if (((i + j) % 2 == 0 ? 'W' : 'B') != arr[i][j])
				cnt++;
            
    return min(cnt, 64 - cnt);
}

int main() {
    int N, M;
    vector<int> v;

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) 
            cin >> arr[i][j];

    for (int i = 0; i <= N - 8; ++i)
        for (int j = 0; j <= M - 8; ++j) 
            v.push_back(solution(i, j));

    cout << *min_element(v.begin(), v.end());
    
}