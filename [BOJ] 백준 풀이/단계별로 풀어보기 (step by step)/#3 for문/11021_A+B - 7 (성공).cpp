#include <iostream>

int main()
{
    int val, x, y;

    std::cin >> val;

    for (int i = 1; i <= val; i++)
    {
        std::cin >> x >> y;
        std::cout << "Case #" << i << ": " << x + y << "\n";
    }

    return 0;
}