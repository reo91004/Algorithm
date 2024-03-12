#include <algorithm>
#include <iostream>
#include <vector>

class pair {
   public:
    int age;
    std::string name;
    int idx;
};

bool cmp(pair a, pair b) {
    if (a.age == b.age)
        return a.idx < b.idx;
    else
        return a.age < b.age;
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

    for (int i = 0; i < N; ++i) {
		std::cin >> v[i].age >> v[i].name;
        v[i].idx = i;
    } 

	std::sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); ++i) 
		std::cout << v[i].age << " " << v[i].name << "\n";

    return 0;
}