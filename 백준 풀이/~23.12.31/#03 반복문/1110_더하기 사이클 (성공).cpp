#include <iostream>

int main()
{
    int init, num;
    int cnt = 0;

    std::cin >> num;

    init = num;

    do {

        num = (num % 10) * 10 + ((num / 10) + (num % 10)) % 10;
        cnt++;

    } while (init != num);

    std::cout << cnt;

    return 0;
}