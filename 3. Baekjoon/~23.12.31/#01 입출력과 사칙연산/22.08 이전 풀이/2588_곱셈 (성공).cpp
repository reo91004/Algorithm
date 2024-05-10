#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;
    cout << a * (b % 10) << '\n';        //3번에 해당하는 코드
    cout << a * ((b / 10) % 10) << '\n'; //4번에 해당하는 코드
    cout << a * (b / 100) << '\n';       //5번에 해당하는 코드
    cout << a * b << '\n';               //6번에 해당하는 코드
}
