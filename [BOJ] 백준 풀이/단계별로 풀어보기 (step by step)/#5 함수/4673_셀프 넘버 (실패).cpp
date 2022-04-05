#include <iostream>

int num_sum(int num) {
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;

        num /= 10;
    }
    return sum;
}

int main() {

    int number[10001];

    for (int i = 0; i <= 10000; i++) {
        number[i] = i;
    }

    int non_self_num;

    for (int i = 0;i <= 10000;i++) {
        non_self_num = i + num_sum(i);
        number[non_self_num] = 0;
    }

    for (int i = 0;i <= 10000;i++) {
        if (number[i] != 0)
            std::cout << number[i] << std::endl;
    }


    return 0;
}