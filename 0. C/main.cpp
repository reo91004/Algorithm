#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> res(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i)
            left[i] = left[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; --i)
            right[i] = right[i + 1] * nums[i + 1];

        for (int i = 0; i < nums.size(); ++i)
            res[i] = left[i] * right[i];

        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4};
    solution.productExceptSelf(nums);
    // std::cout << "Result: " << solution.productExceptSelf(nums) << std::endl;
    string str;
    str = "12";
    str += 1;
    cout << str << "\n";
    return 0;
}