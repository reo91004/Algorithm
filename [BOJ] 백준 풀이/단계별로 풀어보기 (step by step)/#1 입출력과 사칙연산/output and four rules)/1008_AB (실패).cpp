#include <iostream>

using namespace std;

int main()
{
    double a, b;

    cin >> a >> b;

    if ((a > 0 && a < 10 || b > 0 && b < 10) && b != 0) 
    {
        cout << a / b;
    }

    return 0;
}