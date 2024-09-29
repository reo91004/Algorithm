#include <iostream>
#include <algorithm>
#include <vector>

int dp[21][22][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if (dp[a][b][c] != 0)
        return dp[a][b][c];
    else if (a < b && b < c) 
        return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

	int a, b, c;

	while (true) {
		std::cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;
		
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

    return 0;
}