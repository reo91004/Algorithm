#include <iostream>

int main()
{
    std::cin.tie(NULL); // cin으로 데이터를 읽을 때 출력 버퍼에 있는 내용을 비우지 않고 먼저 입력받음.
    std::ios::sync_with_stdio(false); // C와 C++의 버퍼를 분리함.

    int val;

    std::cin >> val;

    for (int i=1; i<=val; i++)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << x + y << "\n"; // endl는 cin처럼 출력 버퍼를 지우므로 \n
    }

    return 0;
}