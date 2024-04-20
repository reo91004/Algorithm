#include <algorithm>
#include <iostream>
#include <vector>

bool cmp(std::string a, std::string b) {
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int N;
    std::cin >> N;
    std::vector<std::string> v(N);

    for (int i = 0; i < N; ++i) std::cin >> v[i];

    std::sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); ++i) 
        std::cout << v[i] << "\n";
}