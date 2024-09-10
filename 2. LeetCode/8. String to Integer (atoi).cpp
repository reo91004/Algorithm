#include <cctype> // for std::isdigit
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string>

class Solution {
public:
    int myAtoi(const std::string &str) {
        int i = 0, sign = 1;
        long result = 0; // long을 사용하여 오버플로우 방지

        // 1. 공백 스킵
        while (i < str.size() && std::isspace(str[i])) {
            i++;
        }

        // 2. 부호 존재하면 처리
        if (i < str.size() && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. 숫자로 변환
        while (i < str.size() && std::isdigit(str[i])) {
            int digit = str[i] - '0';

            // 4. 오버플로우, 언더플로우 처리
            if (result > (std::numeric_limits<int>::max() - digit) / 10) {
                return (sign == 1) ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
            }

            result = result * 10 + digit;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};

int main() {
    Solution sol;
    std::cout << sol.myAtoi("-42") << std::endl; // -42
    return 0;
}
