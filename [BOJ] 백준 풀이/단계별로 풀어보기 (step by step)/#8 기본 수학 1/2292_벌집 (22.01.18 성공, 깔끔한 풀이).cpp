#include <iostream>

using namespace std;

void solution(int N)
{
    int cnt = 1;
    int layer = 1;

    while (N > cnt) 
    {
        cnt += 6 * layer;
        layer++;
    }

    cout << layer;
}

int main()
{
    int N;

    cin >> N;

    solution(N);

    return 0;
}