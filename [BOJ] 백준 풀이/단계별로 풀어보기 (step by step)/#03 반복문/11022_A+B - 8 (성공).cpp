#include <iostream>

int main()
{
    int val, x, y;

    std::cin >> val;

    for (int i = 1; i <= val; i++)
    {
        std::cin >> x >> y; // 반복될때마다 입력받음
        std::cout << "Case #" << i << ": " << x << " + " << y << " = " << x + y << "\n";
    }

    return 0;
}