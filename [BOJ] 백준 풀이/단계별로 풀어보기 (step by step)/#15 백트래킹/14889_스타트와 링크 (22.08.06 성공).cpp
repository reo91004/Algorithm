#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int N;
bool visited[20];
int res = 201;

void dfs(std::vector<std::vector<int>> &v, int cur, int idx) {
    // cur이 N / 2와 같다면 한 팀에 총 인원의 반이 담겨졌다는 의미이므로 멈추고 능력치의 차이를 계산함.
    if (cur == N / 2) {
        int res1 = 0, res2 = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // visited[i]가 true인 사람과 false인 사람으로 나눠지므로 능력치를 더하면 됨.
                if (visited[i] && visited[j])
                    res1 += v[i][j];
                else if (!visited[i] && !visited[j])
                    res2 += v[i][j];
            }
        }

        res = std::min(res, abs(res1 - res2));
        return;
    }
        
    // idx부터 탐색, 만약 i가 방문하지 않았다면 아무런 팀에 담겨있지 않다는 뜻이므로 i + 1인자를 넘겨줘 다음 사람부터 탐색하도록 함.
    for (int i = idx; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(v, cur + 1, i + 1);
            visited[i] = false;
        }
    }
}

void init() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main() {
    init();

    std::cin >> N;

    std::vector<std::vector<int>> v(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j)
            std::cin >> v[i][j];
    
    dfs(v, 0, 0);

    std::cout << res << "\n";

    return 0;
}