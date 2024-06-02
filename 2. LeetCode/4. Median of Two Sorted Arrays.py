from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged_arr = sorted(nums1 + nums2)

        N = len(merged_arr)
        mid = N // 2

        if N % 2 == 1:
            return merged_arr[mid]
        else:
            return (merged_arr[mid - 1] + merged_arr[mid]) / 2
