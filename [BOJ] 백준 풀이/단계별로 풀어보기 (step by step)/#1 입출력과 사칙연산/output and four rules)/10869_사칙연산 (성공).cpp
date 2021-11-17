#include <iostream>

using namespace std;

int main()
{
    int64_t a, b;

    cin >> a >> b;

    if ((a > 0 && a <= 10000 || b > 0 && b <= 10000)) 
    {
        cout << a + b << endl;
        cout << a - b << endl;
        cout << a * b << endl;

        if (b != 0)
            cout << a / b << endl;

        cout << a % b << endl; 
    }

    return 0;
}