#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> BoolArray;

int main() {
    int M, N;

    while (cin >> M >> N) {
        if (M == 0 && N == 0) {
            break;
        }

        cout << (M > N ? "Yes" : "No") << "\n";
    }

    return 0;
}
