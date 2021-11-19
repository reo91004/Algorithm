#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string hakjum[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

int calc(int A, int B, int C) {
	return (((double)A * 35 / 100) + ((double)B * 45 / 100) + ((double)C * 20 / 100));
}

int main() {
	int T; // 테스트 케이스
	int N;
	int K;

	int *A, *B, *C;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> K;

		A = new int[N];
		B = new int[N];
		C = new int[N];

		vector<pair<int, int>> score(N);

		for (int j = 0; j < N; j++)
			cin >> A[j] >> B[j] >> C[j];

		for (int j = 0; j < N; j++) {
			score[j].first = calc(A[j], B[j], C[j]);
			score[j].second = j;
		}

		sort(score.begin(), score.end());

		for (int j = 0; j < N; j++) {
			if (score[j].second == K - 1) {
				int rank = N - j;

				if (N == 10) {
					cout << "#" << i + 1 << " " << hakjum[rank - 1] << "\n";
					break;
				}
				else {
					if (rank <= (N / 10)) {
						cout << "#" << i + 1 << " " << hakjum[0] << "\n";
						break;
					}
					else if (rank % (N / 10) != 0) {
						cout << "#" << i + 1 << " " << hakjum[rank / (N / 10)] << "\n";
						break;
					}
					else if (rank % (N / 10) == 0) {
						cout << "#" << i + 1 << " " << hakjum[rank / (N / 10) - 1] << "\n";
						break;
					}
				}
			}
		}

		score.clear();
	}
	
	return 0;
}