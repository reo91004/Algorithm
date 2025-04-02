#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int XA, YA, XB, YB, XC, YC;
    cin >> XA >> YA >> XB >> YB >> XC >> YC;

    double answer = 0.0;

    // 기울기가 같은지
    if ((XA - XB) * (YA - YC) == (YA - YB) * (XA - XC)) {
        answer = -1.0;
    } else {
        double dist_AB = sqrt(pow(XA - XB, 2) + pow(YA - YB, 2));
        double dist_BC = sqrt(pow(XB - XC, 2) + pow(YB - YC, 2));
        double dist_CA = sqrt(pow(XC - XA, 2) + pow(YC - YA, 2));

        answer = (max({dist_AB, dist_BC, dist_CA}) - min({dist_AB, dist_BC, dist_CA})) * 2;
    }

    cout << answer << endl;

    return 0;
}