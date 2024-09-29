#include <iostream>

using namespace std;

int solution(int N) {
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    else
        return solution(N - 1) + solution(N - 2);
}

int main() {
    int N;
    cin >> N;

    cout << solution(N);
}