#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    int A, B, sum = 0;
    std::cin >> A >> B;

    std::map<int, bool> mp;

    for (int i = 0; i < A + B; ++i) {
        int tmp;
		std::cin >> tmp;

        // 입력받을 때마다 없으면 추가, 존재하면 삭제
		if (mp[tmp] == true)
			mp.erase(tmp);
		else
			mp[tmp] = true;
	}

    std::cout << mp.size();
}