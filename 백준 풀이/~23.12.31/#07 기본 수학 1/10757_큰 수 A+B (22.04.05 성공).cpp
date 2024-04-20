#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int len = max(A.size(), B.size());
    vector<int> v;
    bool carry = false;
    int i, tmp;

    for (i = 0; i < len; ++i) {
        tmp = carry;
        carry = false;

        if (i < A.size()) tmp += A[A.size() - i - 1] - '0';
        if (i < B.size()) tmp += B[B.size() - i - 1] - '0';

        if (tmp >= 10) {
            carry = true;
            tmp -= 10;
        }

        v.insert(v.begin(), tmp);
    }

    if (carry) v.insert(v.begin(), 1);

    for (int i = 0; i < v.size(); ++i) cout << v[i];
}