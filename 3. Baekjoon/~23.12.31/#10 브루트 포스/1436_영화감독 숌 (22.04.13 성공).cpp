#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solution(int val) {
    int cnt = 0;

    while (val) {
        if (val % 10 == 6)
            cnt++;
        else
            cnt = 0;

        if (cnt >= 3)
            return true;

        val /= 10;
    }

    return false;
}

int main() {
    int N, val, start = 666;
    cin >> N;

    while (N) {
        if (solution(start))
            N--;
        
        start++;
    }

    cout << start - 1 << "\n";
}