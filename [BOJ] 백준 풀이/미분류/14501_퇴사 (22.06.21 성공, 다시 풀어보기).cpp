#include <algorithm>
#include <iostream>
#include <vector>

int max = 0;

class pair {
    public:
        int T; // 기간
        int P; // 보수
};

void solution(std::vector<pair> &v, int N, int now, int sum) {
    // 현재 날짜가 퇴사일이라면
    if(now == N){
        max = std::max(max, sum);
        return;
    }
    // 현재 날짜가 퇴사일보다 이후 날짜면 불가 
    else if (now > N)
        return;

    solution(v, N, now + 1, sum);
    solution(v, N, now + v[now].T, sum + v[now].P);
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

    std::vector<pair> v(N + 1);

    for (int i = 0; i < N; ++i)
        std::cin >> v[i].T >> v[i].P;

    solution(v, N, 0, 0);

    std::cout << max;

    return 0;
}