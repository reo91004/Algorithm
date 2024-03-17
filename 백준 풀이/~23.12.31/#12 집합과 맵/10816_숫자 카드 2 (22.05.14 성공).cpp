#include <algorithm>
#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int N, M;
    std::cin >> N;
    std::vector<int> v1(N);

    for (int i = 0; i < N; ++i) 
        std::cin >> v1[i];
    
    std::cin >> M;
    std::vector<int> v2(M);

    for (int i = 0; i < M; ++i)
        std::cin >> v2[i];

    std::sort(v1.begin(), v1.end());

    for (int i = 0; i < M; ++i) {
        if (std::binary_search(v1.begin(), v1.end(), v2[i])) {
            std::cout << std::upper_bound(v1.begin(), v1.end(), v2[i]) -  std::lower_bound(v1.begin(), v1.end(), v2[i]) << " ";
        }
        else
            std::cout << "0 ";
    }
    
    return 0;
}