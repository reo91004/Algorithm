from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return len(nums)  # 길이가 2 이하일 경우 이미 조건을 만족

        # Two pointer approach
        slow = 2  # 처음 두 개는 그대로 두므로 slow는 2부터 시작
        for fast in range(2, len(nums)):
            # fast 포인터가 가리키는 값이 slow 포인터 바로 앞 두 개의 값과 다를 때
            if nums[fast] != nums[slow - 2]:
                nums[slow] = nums[fast]  # 값을 옮김
                slow += 1  # 중복을 허용한 위치를 증가

        return slow  # slow 포인터가 중복을 제거한 배열의 길이를 반환


# 다른 풀이
#     def removeDuplicates(self, nums: List[int]) -> int:
#         if not nums:
#             return 0

#         idx = 1
#         count = 1

#         for i in range(1, len(nums)):
#             if nums[i] == nums[i - 1]:
#                 count += 1
#             else:
#                 count = 1

#             if count <= 2:
#                 nums[idx] = nums[i]
#                 idx += 1

#         return idx


# 예제 테스트
sol = Solution()
print(sol.removeDuplicates([0, 0, 1, 1, 1, 1, 2, 3, 3]))
