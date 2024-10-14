#include <iostream>
#include <numeric>
#include <string>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    long long sum_A = 0, sum_B = 0;

    for (char a : A) {
        sum_A += a - '0';
    }

    for (char b : B) {
        sum_B += b - '0';
    }

    long long result = sum_A * sum_B;

    cout << result << endl;

    return 0;
}