#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        vector<int> res(nums.size());

        for (int i = 1; i < nums.size(); ++i)
            left[i] = left[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; --i)
            right[i] = right[i + 1] * nums[i + 1];

        for (int i = 0; i < nums.size(); ++i)
            res[i] = left[i] * right[i];

        return res;
    }
};