#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> MonthDays;
typedef vector<string> WeekDays;

int main() {
    int day = 0;
    MonthDays month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    WeekDays week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int x, y;
    cin >> x >> y;

    // x월까지 순회해서 day 카운트
    for (int i = 0; i < x - 1; i++) {
        day += month[i];
    }

    // mod 연산으로 요일 탐색
    day = (day + y) % 7;

    cout << week[day] << endl;

    return 0;
}
