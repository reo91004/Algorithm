#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];

void solution(vector<pair<int, int>>& v, int N, int K) {
	// 총 물품의 갯수만큼 반복
	for (int i = 1; i <= N; i++) {
		// 가방의 무게만큼 반복
		for (int j = K; j >= 1; j--) {
			// 만약 가방의 무게가 i번째 물품의 무게보다 클 때
			if (j - v[i].first >= 0)
				// 이전 물품을 넣었을 때의 가치 vs 현재 넣을 물품의 무게만큼을 뺀 이전 물품을 넣었을 때의 가치와 현재 물품의 합
				dp[j]= max(dp[j], dp[j - v[i].first] + v[i].second);
			
		}
	}

	cout << dp[K];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; // 총 물품 갯수, 가방 무게

	cin >> N >> K;

	vector<pair<int, int>> v(N + 1); // 순서대로 물건의 무게, 가치

	v[0].first = 0;
	v[0].second = 0;

	for (int i = 1; i <= N; i++)
		cin >> v[i].first >> v[i].second;

	solution(v, N, K);

	return 0;
}