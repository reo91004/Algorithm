#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int val;

    std::cin >> val;

    for (int i = 1; i <= val; i++)
        std::cout << i << "\n";

    return 0;
}