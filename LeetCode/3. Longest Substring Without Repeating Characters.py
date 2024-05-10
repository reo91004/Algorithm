from typing import List


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        visit = set()
        left = 0  # 왼쪽 idx

        # 오른쪽 idx부터 시작
        for right in range(len(s)):
            # visit에 있다면, visit에서 삭제하고 left 인덱스 증가
            # left와 right를 이용해 전체 길이 구함
            while s[right] in visit:
                visit.remove(s[left])
                left += 1
            # visit에 문자 추가
            visit.add(s[right])
            res = max(res, right - left + 1)
        return res


s = Solution()
print(s.lengthOfLongestSubstring("pwwkew"))
