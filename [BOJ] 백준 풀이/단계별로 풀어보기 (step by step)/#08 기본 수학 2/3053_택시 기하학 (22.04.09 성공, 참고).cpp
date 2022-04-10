#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r;
    cout << fixed;
    cout.precision(6);
    cin >> r;

    cout << pow(r, 2) * M_PI << "\n";
    cout << pow(r, 2) * 2;

    return 0;
}