#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> IntVector;

IntVector solution(int N, int K) {
    IntVector people;
    IntVector result;

    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }

    // 현재 위치
    int index = 0;

    // 모든 사람이 제거될 때까지 반복
    while (!people.empty()) {
        // K번째 사람의 인덱스 계산
        index = (index + K - 1) % people.size();
        // K번째 사람을 제거하고 결과에 추가
        result.push_back(people[index]);
        people.erase(people.begin() + index);
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K; // 사람 수, 양의 정수

    IntVector answer = solution(N, K);

    // 결과 출력
    cout << "<";
    for (size_t i = 0; i < answer.size(); ++i) {
        cout << answer[i];
        if (i != answer.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    return 0;
}