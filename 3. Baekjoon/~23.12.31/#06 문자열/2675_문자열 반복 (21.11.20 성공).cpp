#include <iostream>
#include <string>

using namespace std;

void solution(int R, string str)
{
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cout << str[i];
        }
    }

    cout << "\n";
}

int main()
{
    int T; // 테스트 케이스
    int R; // 반복 횟수
    string str;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> R >> str;

        solution(R, str);
    }
}