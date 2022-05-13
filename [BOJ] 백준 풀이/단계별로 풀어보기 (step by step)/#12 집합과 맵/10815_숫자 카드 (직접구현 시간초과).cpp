#include <algorithm>
#include <iostream>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

bool mybinary_search(std::vector<int> v, int N, int key) {
    int start = 0;
    int end = N - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (v[mid] == key)
            return true;
        else if (v[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return false;
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
        if (mybinary_search(v1, N, v2[i]))
            std::cout << "1 ";
        else
            std::cout << "0 ";
    }
    
    return 0;
}