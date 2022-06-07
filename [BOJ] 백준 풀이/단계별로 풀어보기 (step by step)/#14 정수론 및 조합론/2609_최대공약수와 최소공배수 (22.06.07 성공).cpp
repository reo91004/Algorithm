#include <algorithm>
#include <iostream>
#include <vector>

int gcd(int a, int b) {
    int c;

    while (b != 0) {
        c = a % b; 
        a = b;      
        b = c;      
    }

    return a;
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int a, b;
    std::cin >> a >> b;
    
    int res = gcd(a, b);

    std::cout << res << "\n";
    std::cout << (a * b) / res << "\n";
}