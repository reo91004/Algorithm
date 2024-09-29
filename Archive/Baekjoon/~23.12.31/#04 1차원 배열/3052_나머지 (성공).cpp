#include <iostream>

int main() {
    int arr[42] = {0, };  // 42로 나눈 나머지이므로
    int n;
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        std::cin >> n;
        if (!arr[n % 42]++) sum++;
    }

    std::cout << sum;
}