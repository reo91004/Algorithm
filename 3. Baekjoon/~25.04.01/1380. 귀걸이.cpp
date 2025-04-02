#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> IntVector;
typedef vector<string> StringVector;

int main() {
    int scenario_num = 1;

    while (true) {
        int n;
        cin >> n;
        cin.ignore(); // 입력 버퍼 비우기
        if (n == 0) {
            break;
        }

        StringVector names(n);
        for (int i = 0; i < n; i++) {
            getline(cin, names[i]);
        }

        IntVector counts(n, 0); // 학생별 등장 횟수

        for (int i = 0; i < 2 * n - 1; i++) {
            int a;
            string temp;
            cin >> a >> temp;
            a -= 1;         // 0부터 시작하도록 변환
            counts[a] ^= 1; // 등장 횟수를 XOR로 처리 (0 → 1 → 0)
        }

        int missing = -1;
        for (int i = 0; i < n; i++) {
            if (counts[i] == 1) {
                missing = i;
                break;
            }
        }

        cout << scenario_num << " " << names[missing] << endl;
        scenario_num++;
    }

    return 0;
}