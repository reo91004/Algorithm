#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dist = pow(x1 - x2, 2) + pow(y1 - y2, 2); // 두 점 사이의 거리
        int cmp1 = pow(r1 - r2, 2); // 반지름 차
        int cmp2 = pow(r1 + r2, 2); // 반지름 합

        if (dist == 0) { // 두 점 사이의 거리가 0이고
            if (cmp1 == 0) // 반지름의 차도 0이면 있을 수 있는 곳이 무한대이다. 그림을 그려보자.
                cout << "-1" << "\n";
            else
                cout << "0" << "\n";
        } 
        else if (dist == cmp1 || dist == cmp2) // 접하는 경우이므로 1개다.
            cout << "1" << "\n";
        else if (cmp1 < dist && dist < cmp2) // 겹치는 부분이 2군데다.
            cout << "2" << "\n";
        else
            cout << "0" << "\n";
    }
}