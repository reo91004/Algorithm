#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef unordered_map<string, int> mapsi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    mapsi tag_count;

    for (int i = 0; i < N; i++) {
        int id, t;
        cin >> id >> t;

        string tag;
        for (int j = 0; j < t; j++) {
            cin >> tag;
            tag_count[tag]++;
        }
    }

    // 최대 빈도 찾기
    int max_freq = 0;
    for (const auto &p : tag_count) {
        max_freq = max(max_freq, p.second);
    }

    // 최대 빈도를 가진 태그들 찾기
    vs result;
    for (const auto &p : tag_count) {
        if (p.second == max_freq) {
            result.push_back(p.first);
        }
    }

    // 결과 출력
    if (result.size() > 1) {
        cout << -1 << "\n";
    } else {
        cout << result[0] << "\n";
    }

    return 0;
}