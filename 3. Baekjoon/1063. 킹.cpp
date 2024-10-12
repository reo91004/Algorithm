#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void solution(vector<int> &king, vector<int> &stone, map<string, vector<int>> &move, int N) {
    for (int i = 0; i < N; i++) {
        string m;
        cin >> m;

        // 움직였을 경우의 위치 : dx, dy
        int dx = king[0] + move[m][0];
        int dy = king[1] + move[m][1];

        // 체스판 위에 존재
        if (0 < dx && dx <= 8 && 0 < dy && dy <= 8) {
            // 킹이 돌 위에 올라감
            if (dx == stone[0] && dy == stone[1]) {
                int sx = stone[0] + move[m][0];
                int sy = stone[1] + move[m][1];
                // 돌도 체스판 위에 존재하면 둘 다 이동
                if (0 < sx && sx <= 8 && 0 < sy && sy <= 8) {
                    king = {dx, dy};
                    stone = {sx, sy};
                }
            } else {
                king = {dx, dy}; // 킹만 이동
            }
        }
    }

    cout << char(king[0] + 64) << king[1] << endl;
    cout << char(stone[0] + 64) << stone[1] << endl;
}

int main() {
    string king_str, stone_str;
    int N;
    cin >> king_str >> stone_str >> N;

    vector<int> king = {king_str[0] - 'A' + 1, king_str[1] - '0'};
    vector<int> stone = {stone_str[0] - 'A' + 1, stone_str[1] - '0'};

    // 이동 맵 생성
    map<string, vector<int>> move = {
        {"R", {1, 0}},
        {"L", {-1, 0}},
        {"B", {0, -1}},
        {"T", {0, 1}},
        {"RT", {1, 1}},
        {"LT", {-1, 1}},
        {"RB", {1, -1}},
        {"LB", {-1, -1}}};

    solution(king, stone, move, N);

    return 0;
}