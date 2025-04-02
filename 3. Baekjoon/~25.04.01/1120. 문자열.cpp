#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> IntVector;

int main() {
    string A, B;
    cin >> A >> B;

    IntVector result;

    for (size_t i = 0; i <= B.length() - A.length(); ++i) {
        int count = 0;
        for (size_t j = 0; j < A.length(); ++j) {
            if (A[j] != B[j + i]) {
                count++;
            }
        }
        result.push_back(count);
    }

    cout << *min_element(result.begin(), result.end()) << endl;

    return 0;
}