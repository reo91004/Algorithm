#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int Answer;
int bit = 0;

class pair {
   public:
    int P;
    int V;
};

bool compare(const pair &a, const pair &b) { return a.V < b.V; }

void solution(std::vector<pair> &v, std::vector<pair> &res, int N) {
    for (int i = 0; i < N; ++i) {
        pair tmp;
        tmp.P = 0;
        tmp.V = v[i].V;

        auto it = std::lower_bound(res.begin(), res.end(), tmp, compare) - res.begin();

        Answer += abs(v[i].P - v[res[it].P].P);

        res.erase(res.begin() + it);
    }
}

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    
    int T, test_case;
    int N;

    //freopen("test_input.txt", "r", stdin);
    std::cin >> T;

    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        bit = 0;

        std::cin >> N;  // 개미의 마리 수
        std::vector<pair> v(N);

        for (int i = 0; i < N; ++i) std::cin >> v[i].P;

        for (int i = 0; i < N; ++i) std::cin >> v[i].V;

        // 입력 끝

        std::vector<pair> res(N);

        // 해당 벡터의 P, V는 위와 다르다. P는 초기 위치, V는 가치다.
        for (int i = 0; i < N; ++i) res[i].V = v[i].V;

        std::sort(res.begin(), res.end(), compare);

        for (int i = 0; i < N; ++i) res[i].P = i;

        solution(v, res, N);

        std::cout << "Case #" << test_case + 1 << std::endl;
        std::cout << Answer << std::endl;
    }

    return 0;
}