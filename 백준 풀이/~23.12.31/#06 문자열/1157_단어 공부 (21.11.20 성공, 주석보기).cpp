#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int alp[26] = {
    0,
};

void solution(string str)
{
    int max = 0;
    int cnt = 0, val = 0;
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        alp[str[i] - 65]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (max < alp[i])
        {
            val = i;
            max = alp[i];
            cnt = 0;
        }
        if (max == alp[i])
            cnt++;
    }

    if (cnt > 1)
        cout << "?";
    else
        cout << (char)(val + 'A');
}

int main()
{
    string str;

    cin >> str;

    // 왜 안되나 했더니, 맥이나 리눅스에서는 자료형이 모호해져서 (int(*)(int))을 해줘야 한단다. 잘 모르겠다.
    std::transform(str.begin(), str.end(), str.begin(), (int (*)(int))toupper);

    solution(str);
}