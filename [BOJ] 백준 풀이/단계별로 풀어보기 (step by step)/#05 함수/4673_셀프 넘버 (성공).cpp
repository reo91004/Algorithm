#include <iostream>

int non_self_num(int num)
{
    int sum = num;
    while (num != 0)
    {
        sum += num % 10;
        num = num / 10;
    }

    return sum;
}

int main()
{
    bool number[10001] = {false};
    int temp;

    for (int i = 1; i <= 10000; i++)
    {
        temp = non_self_num(i);
        if (temp <= 10000)
            number[temp] = true;
    }


    for (int i = 1; i <= 10000; i++)
        if (number[i] == false)
            std::cout << i << "\n";
}