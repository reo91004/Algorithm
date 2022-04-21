#include <iostream>

using namespace std;

int main() {
	int T; // 테스트 케이스

	cin >> T;

	int D, H, M;
	
	for (int i = 1; i <= T; i++) {
		int res = 0;

		cin >> D >> H >> M;
			
		if (D <= 11 && H <= 11 && M <= 11) {
			if (D == 11 && H == 11 && M == 11) {
				cout << "#" << i << " 0" << "\n";
				continue;
			}

			cout << "#" << i << " -1" << "\n";
			continue;
		}

		res += (D - 11) * 1440;
		res += (H - 11) * 60;
		res += (M - 11);

		cout << "#" << i << " " << res << "\n";
	}
	
	return 0;
}