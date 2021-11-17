#include <iostream>

int main()
{
    int val;

    std::cin >> val;

    for (int i = 1; i < 10; i++)
        std::cout << val << " * " << i << " = " << val * i << std::endl;

    return 0;
}