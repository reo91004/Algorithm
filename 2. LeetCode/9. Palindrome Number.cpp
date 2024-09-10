#include <cctype>
#include <iostream>
#include <limits>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int reversed = 0;
        int original = x;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (reversed > (std::numeric_limits<int>::max() - digit) / 10) {
                return false;
            }

            reversed = reversed * 10 + digit;
        }

        return original == reversed;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isPalindrome(-42) << std::endl; // -42
    return 0;
}
