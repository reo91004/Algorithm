#include <iostream>

int main()
{
    int val, sum = 0;

    std::cin >> val;

    for (int i=1; i<=val; i++)
    {
        sum += i;
    }

    std::cout << sum;
}