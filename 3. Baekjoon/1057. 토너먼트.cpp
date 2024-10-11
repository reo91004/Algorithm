#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int round = 0;

    while (a != b) {
        round++;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }

    return round;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    int result = solution(N, A, B);
    cout << result << "\n";

    return 0;
}
