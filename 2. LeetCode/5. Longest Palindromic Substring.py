from typing import List


class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 중앙에서부터 앞뒤로 팰린드롬 체크
        def calc(left: int, right: int) -> str:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1 : right]

        if len(s) == 0:
            return ""

        longest = ""
        for i in range(len(s)):
            # 홀수 팰린드롬 체크
            odd = calc(i, i)
            if len(odd) > len(longest):
                longest = odd

            # 짝수 팰린드롬 체크
            even = calc(i, i + 1)
            if len(even) > len(longest):
                longest = even

        return longest


# 예제 테스트
sol = Solution()
print(sol.longestPalindrome("babad"))
print(sol.longestPalindrome("cbbd"))
