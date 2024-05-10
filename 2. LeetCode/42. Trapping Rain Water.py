from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0

        res = 0
        H = len(height)
        # Arrays to store the maximum height to the left and right of each element
        leftMax = [0] * H
        rightMax = [0] * H

        leftMax[0] = height[0]
        for i in range(1, H):
            leftMax[i] = max(leftMax[i - 1], height[i])

        rightMax[H - 1] = height[H - 1]
        for i in range(H - 2, -1, -1):
            rightMax[i] = max(rightMax[i + 1], height[i])

        for i in range(H):
            res += min(leftMax[i], rightMax[i]) - height[i]

        return res


s = Solution()
print(s.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
