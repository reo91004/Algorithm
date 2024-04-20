#include <algorithm>
#include <iostream>

int arr[41];

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

	int N; 
    std::cin >> N;

    // 동적 계획법
    arr[1] = arr[2] = 1;
	for (int i = 3; i < 41; ++i) 
        arr[i] = arr[i - 1] + arr[i - 2];

	std::cout << arr[N] << " " << N - 2;

    return 0;
}