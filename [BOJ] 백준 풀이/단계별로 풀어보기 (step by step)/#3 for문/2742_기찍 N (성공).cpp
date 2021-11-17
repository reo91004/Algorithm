#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int val;

    std::cin >> val;

    for (int i = val; i > 0; i--)
        std::cout << i << "\n";

    return 0;
}