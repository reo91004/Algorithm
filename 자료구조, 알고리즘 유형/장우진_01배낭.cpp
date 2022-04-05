#include <algorithm>
#include <iostream>
#include <vector>

int dp[100001];

class product {
   public:
    int weight;
    int value;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<product> input_vec;
    int n, k;
    std::cin >> n >> k;
    input_vec.push_back({0, 0});
    for (int i = 1; i <= n; ++i) {
        int weight, val;
        std::cin >> weight >> val;
        input_vec.push_back({weight, val});
    }  // data input
    // 무게는 k에 저장되어있으니 굳이 따로 저장할필요 없음
    // k 무게를 이용 가능했을때 최대의 가치를 구하자.
    // n은 1부터, 1일땐 1번물건만 이용했을때. 2일땐, 1번,2번 물건을 이용....
    for (int i = 1; i <= n; ++i) {
        for (int j = k; j >= 1; --j) {
            if (j >= input_vec[i].weight)
                dp[j] = std::max(
                    dp[j], dp[j - input_vec[i].weight] + input_vec[i].value);
        }  // 2번 물건을 이용할때, 이전 물건들로만 채웠을때 나올수 있는 최댓값
           // vs 이번 물건을 꼭 이용했을때 나오는 최댓값
    }
    std::cout << dp[k];
    return 0;
}