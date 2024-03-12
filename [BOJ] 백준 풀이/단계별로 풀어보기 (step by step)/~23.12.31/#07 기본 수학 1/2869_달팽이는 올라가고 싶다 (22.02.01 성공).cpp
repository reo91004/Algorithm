#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;

    int diff = A - B;

    if ((V - A) % diff == 0)
        cout << (V - A) / diff + 1;
    else
        cout << (V - A) / diff + 2;
}