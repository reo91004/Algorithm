#include <iostream>

using namespace std;

void solution(int N)
{
    int layer = 0;

    if (N == 1)
        cout << 1;
    else
    { // N이 1일때는 위의 if문에서 걸러지므로 2부터 시작
        for (int i = 2; i <= N; ++layer)
            i += 6 * layer;
        cout << layer;
    }
}

int main()
{
    int N;

    cin >> N;

    solution(N);

    return 0;
}