from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        del nums1[m:]
        del nums2[n:]
        nums1.extend(nums2)
        nums1.sort()


if __name__ == "__main__":
    sol = Solution()
    print(
        sol.merge(nums1=[1, 2, 3, 0, 0, 0], m=3, nums2=[2, 5, 6], n=3)
    )  # [1, 2, 2, 3, 5, 6]
