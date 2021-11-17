#include <iostream>

int main(void)
{
    int val, a, b;

    std::cin >> val;

    for(int i=0; i<val; i++)
    {
        std::cin>> a >> b;
        std::cout << a + b << std::endl;
    }
}