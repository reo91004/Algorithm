#include <iostream>

using namespace std;

void solution(int i, int j, int N) {
    if ((i / N) % 3 == 1 && (j / N) % 3 == 1)  // 이 조건일 때 빈칸
        cout << " ";
    // 이미 위 조건에서 걸러진다는 것은 별이 찍혀야 한다는 의미인데, 이 문제를
    // 재귀적으로 해결하기 위해서는 재귀 조건이 있어야 한다. 현재 정사각형의
    // 크기가 9 이상이면 (N이 3 이상이면) 탐색할 수 있는 공백이 있지만 1이라면 공백이 없으므로
    // 그대로 *을 출력한다. (N / 3 == 0과 같다)
    else if (N == 1)
        cout << "*";
    else
        solution(i, j, N / 3);
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) 
            solution(i, j, N);

        cout << "\n";
    }
}