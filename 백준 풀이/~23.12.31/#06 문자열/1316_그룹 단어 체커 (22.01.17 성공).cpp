#include <iostream>
#include <string>

using namespace std;

int solution(int N)
{
    int cnt = N;
    string str;

    for (int i = 0; i < N; ++i)
    {
        cin >> str;

        int alp[26] = {0};
        int len = str.length();

        for (int j = 0; j < len; ++j)
        {
            if (alp[str[j] - 'a'] == 0)
                alp[str[j] - 'a'] = 1;

            else if ((alp[str[j] - 'a'] == 1) && (str[j] != str[j - 1]))
            {
                cnt--;
                break;
            }
        }
    }

    return cnt;
}

int main()
{
    int N; // 단어의 개수
    cin >> N;

    cout << solution(N);
}