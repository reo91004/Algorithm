#include <iostream>

int main()
{
    int x, y;

    std::cin >> x >> y;

    if (y < 45) // 만약 분이 45보다 작다면 시 부분을 바꿔야 한다.
    {
        y = 60 - 45 + y; // y를 남은 시간으로 바꾸어 줌.
        x = (x + 24 - 1) % 24; // x가 음수가 나오면 안되므로 나머지 연산 이용한다.
        std::cout << x << " " << y;
    }
    else
        std::cout << x << " " << y - 45;

    return 0;
}