#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        set<char> visit;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            while (visit.find(s[right]) != visit.end()) {
                visit.erase(s[left]);
                left++;
            }
            visit.insert(s[right]);
            res = max(res, right - left + 1);
        }

        return res;
    }
};

int main() {
    Solution solution;
    string test = "pwwkew";
    cout
        << solution.lengthOfLongestSubstring(test) << endl;
    return 0;
}
