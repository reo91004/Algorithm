#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    while (x && y && z) {
        if (x > y)
            swap(x, y);
        if (y > z)
            swap(y, z);
        
        if (z * z == x * x + y * y)
            cout << "right\n";
        else
            cout << "wrong\n";
        
        cin >> x >> y >> z;
    }

    return 0;
}