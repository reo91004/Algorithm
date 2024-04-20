#include <iostream>

using namespace std;

void solution(int A, int B, int C)
{
    if (B >= C)
        cout << "-1";
    else 
        cout << A / (C - B) + 1;
}

int main() 
{
    int A, B, C; // A는 고정, B는 가변, C는 가격

    cin >> A >> B >> C;

    solution(A, B, C);

    return 0;
}