from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums = sorted(nums)
        res = 0

        for i in range(0, len(nums), 2):
            res += nums[i]

        return res


s = Solution()
print(s.arrayPairSum([6, 2, 6, 5, 1, 2]))
