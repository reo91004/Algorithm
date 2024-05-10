#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void quickSort(std::vector<int> &nums, int left, int right) {
        if (left >= right)
            return;

        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

    int partition(std::vector<int> &nums, int left, int right) {
        int pivot = nums[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums[right]);
        return i + 1;
    }

    int arrayPairSum(std::vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        int res = 0;

        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }

        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 4, 3, 2};
    std::cout << "Result: " << solution.arrayPairSum(nums) << std::endl;
    return 0;
}