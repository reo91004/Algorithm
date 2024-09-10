from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        uniqueIndex = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[uniqueIndex] = nums[i]
                uniqueIndex += 1

        return uniqueIndex
