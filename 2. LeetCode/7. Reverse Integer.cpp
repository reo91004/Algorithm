#include <climits> // INT_MAX, INT_MIN
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // 오버플로우 체크
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
                return 0;

            result = result * 10 + pop;
        }

        return result;
    }
};

int main() {
    Solution solution;
    int testValue = 123; // 테스트할 값
    int reversedValue = solution.reverse(testValue);

    std::cout << "Original: " << testValue << std::endl;
    std::cout << "Reversed: " << reversedValue << std::endl;

    return 0;
}
