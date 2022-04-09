#include <iostream>
#include <cmath>

using namespace std;

int solution(int N) {
    if (N <= 1)
        return 1;
    else
        return N * solution(N - 1);
}

int main() {
    int N;
    cin >> N;

    cout << solution(N);
}