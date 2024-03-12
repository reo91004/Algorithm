#include <iostream>

int main()
{
    int A, B;

    while (1)
    {
        std::cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        else
            std::cout << A + B << "\n";
    }
}