#include <algorithm>
#include <iostream>
#include <vector>

class pair {
   public:
    long long two;
    long long five;
};

pair solution(long long num) {
    long long two = 0, five = 0;

    for (long long i = 2; i <= num; i *= 2) 
        two += num / i;
    for (long long i = 5; i <= num; i *= 5) 
        five += num / i;

    return {two, five};
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    long long N, M;
    std::cin >> N >> M;
    
    std::vector<pair> v(3);

    v[0] = solution(N);
    v[1] = solution(M);
    v[2] = solution(N - M);

    std::cout << std::min(v[0].two - v[1].two - v[2].two, v[0].five - v[1].five - v[2].five) << "\n";

    return 0;
}