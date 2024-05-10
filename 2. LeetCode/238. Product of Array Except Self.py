from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [1] * n
        right = [1] * n
        res = [1] * n

        # 왼쪽 누적 곱 계산
        for i in range(1, n):
            left[i] = left[i - 1] * nums[i - 1]

        # 오른쪽 누적 곱 계산
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * nums[i + 1]

        # 결과 리스트 계산
        for i in range(n):
            res[i] = left[i] * right[i]

        return res


s = Solution()
print(s.productExceptSelf(nums=[1, 2, 3, 4]))
