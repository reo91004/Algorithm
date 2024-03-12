#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void solution(string str)
{
    int len = str.length();
    int cnt = 0;

    for (int i = 0; i < len; i++)
    {
        if (isspace(str[i]))
            if (isspace(str[i]) != 0 || isspace(str[i + 1]) != 0)
                cnt++;
    }

    if (isspace(str[0]) == 0 && isspace(str[len - 1]) == 0)
        cnt++;
    if (isspace(str[0]) != 0 && isspace(str[len - 1]) != 0)
        cnt--;

    cout << cnt;
}

int main()
{
    string str;

    getline(cin, str);

    solution(str);

    return 0;
}