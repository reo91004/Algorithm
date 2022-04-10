#include <iostream>

using namespace std;

int main()
{
    int N, res = 0; // 숫자의 갯수, 결괏값
    char num;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        res += num - 48;
    }

    cout << res;

    return 0;
}