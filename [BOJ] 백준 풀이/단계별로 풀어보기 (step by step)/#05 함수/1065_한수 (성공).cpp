#include <iostream>

int han(int num)
{
    int i, j, k;
    if (num < 100)
        return 1;
    else
    {
        i = num / 100;
        j = num % 100 / 10;
        k = num % 100 % 10;

        if (i + k == 2 * j && (i < j < k || i > j > k))
            return 1;
        else
            return 0;
    }
}

int main()
{
    int N;
    int temp;
    int count = 0;

    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        temp = han(i);
        if (temp == 1)
        {
            count++;
        }
    }

    std::cout << count << "\n";
}