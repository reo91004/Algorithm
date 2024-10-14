#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;

    // 입력받기
    getline(cin, text);

    reverse(text.begin(), text.end());

    cout << text << "\n";

    return 0;
}