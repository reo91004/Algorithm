#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int A, B;
    std::cin >> A >> B;

    std::cout << A * (B % 10) << "\n";        //3번에 해당하는 코드
    std::cout << A * ((B / 10) % 10) << "\n"; //4번에 해당하는 코드
    std::cout << A * (B / 100) << "\n";       //5번에 해당하는 코드
    std::cout << A * B << "\n";               //6번에 해당하는 코드

    return 0;
}