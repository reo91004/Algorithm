#include <iostream>

int main()
{
    int val;

    std::cin >> val;

    for (int i = 1; i <= val; i++)
        std::cout << i << std::endl;

    return 0;
}