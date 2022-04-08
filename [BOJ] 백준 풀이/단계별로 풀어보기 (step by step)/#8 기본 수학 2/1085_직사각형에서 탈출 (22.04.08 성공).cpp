#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int x, y, w, h;
    int res1, res2;

    cin >> x >> y >> w >> h;
    res1 = min(x, y);
    res2 = min(w - x, h - y);

    cout << min(res1, res2) << "\n";

    return 0;
}