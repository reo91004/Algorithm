#include <iostream>
#include <string>

using namespace std;

void solution(string str)
{
    int num[] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
    int res = 0;
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        res += num[str[i] - 'A'];
    }

    cout << res;
}

int main()
{
    string str;

    cin >> str;

    solution(str);

    return 0;
}