#include <iostream>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main()  {
    init();
    
    int score;
    std::cin >> score;

    if (100 >= score && score >= 90)
        std::cout << 'A';
    else if (89 >= score && score >= 80)
        std::cout << 'B';
    else if (79 >= score && score >= 70)
        std::cout << 'C';
    else if (69 >= score && score >= 60)
        std::cout << 'D';
    else
        std::cout << 'F';

    return 0;
}