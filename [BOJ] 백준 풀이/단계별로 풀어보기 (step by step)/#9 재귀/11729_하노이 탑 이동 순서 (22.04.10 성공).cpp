#include <iostream>

using namespace std;

// 순서대로 start, mid, end 장대라고 가정하자.
// 하노이탑 과정을 통째로 생각하면, n-1개의 원판을 mid에 옮기고
// 나머지 원판을 end로 옮기고, 다시 mid에 있는 원판들을 end에 옮기면 된다.
void solution(int N, int start, int mid, int end) {
    if (N == 1)
        cout << start << " " << end << "\n";
    else {
        solution(N - 1, start, end, mid);
        cout << start << " " << end << "\n";
        solution(N - 1, mid, start, end);
    }
}

int main() {
    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";
    solution(N, 1, 2, 3);

    return 0;
}