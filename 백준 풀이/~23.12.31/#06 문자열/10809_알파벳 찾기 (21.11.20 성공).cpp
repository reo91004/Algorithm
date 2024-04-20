#include <iostream>

using namespace std;

int main()
{
    int alp[26];
    char c;
    int i = -1;

    for (int k = 0; k < 26; k++)
    {
        alp[k] = -1;
    }

    do
    {
        cin.get(c);
        i++;
        if (alp[c - 97] != -1)
            continue;

        alp[c - 97] = i;
    } while (c != '\n');

    for (i = 0; i < 26; i++)
    {
        cout << alp[i] << " ";
    }
}