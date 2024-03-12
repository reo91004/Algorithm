#include <iostream>

int main()
{
    int arr[10] = {0, };
    int a, b, c;
    int result;

    std::cin >> a >> b >> c;

    result = a * b * c;

    while (result > 0)
    {
        arr[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << "\n";
}