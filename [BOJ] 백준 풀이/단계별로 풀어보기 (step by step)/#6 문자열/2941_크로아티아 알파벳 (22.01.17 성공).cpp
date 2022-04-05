#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> arr = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    int val;
    int len = arr.size();
    string str;

    cin >> str;

    for (int i = 0; i < len; i++) {
        while (true) {
            val = str.find(arr[i]);
            if (val == string::npos)
                break;
                
            str.replace(val, arr[i].length(), "!");
        }
    }
    cout << str.length();
}