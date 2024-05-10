#include <iostream>

int main()
{
    int val;

    std::cin >> val;

    for (int i=1; i<=val; i++)
    {
        for (int j=0; j<i; j++)
        {
            std::cout << "*";
        }
        
        std::cout << "\n";
    }
}