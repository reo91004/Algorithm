#include <algorithm>
#include <iostream>
#include <vector>

class pair {
   public:
    int x;
    int y;
};

bool cmp(pair a, pair b) {
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
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
    std::vector<pair> v(N);

    for (int i = 0; i < N; ++i) 
		std::cin >> v[i].x >> v[i].y;

    std::sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; ++i) 
		std::cout << v[i].x << " " << v[i].y << "\n";
}