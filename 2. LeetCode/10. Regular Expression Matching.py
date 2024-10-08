from typing import List
from itertools import zip_longest


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # DP 테이블 초기화
        dp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]

        # 빈 문자열과 빈 패턴은 매치됨
        dp[0][0] = True

        # 패턴이 '*'로 시작하는 경우 처리
        # 이 경우 빈 패턴과 매치될 수 있음
        for j in range(1, len(p) + 1):
            if p[j - 1] == "*":
                dp[0][j] = dp[0][j - 2]

        # DP 테이블 채우기
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                # 현재 문자가 매치되는 경우 (같은 문자이거나 '.'인 경우)
                if p[j - 1] == s[i - 1] or p[j - 1] == ".":
                    # 현재 문자가 매치되면, 이전 상태의 매치 여부를 그대로 가져옴
                    # 즉, 현재 문자를 제외한 이전까지의 매치 상태를 유지
                    dp[i][j] = dp[i - 1][j - 1]

                # 현재 패턴 문자가 '*'인 경우
                elif p[j - 1] == "*":
                    # 1. '*' 앞의 문자를 무시하는 경우 (0번 사용)
                    # '*'와 그 앞의 문자를 모두 무시하고, 그 이전 상태의 매치 여부를 가져옴
                    dp[i][j] = dp[i][j - 2]

                    # 2. '*' 앞의 문자가 현재 문자와 매치되거나 '.'인 경우
                    if p[j - 2] == s[i - 1] or p[j - 2] == ".":
                        # '*' 앞의 문자를 한 번 이상 사용하는 경우
                        # 현재 문자를 매치시키고, 이전 문자열 상태의 매치 여부를 확인
                        # 'or' 연산은 이전 단계(dp[i][j - 2])와 현재 단계 중 하나라도 참이면 참
                        dp[i][j] = dp[i][j] or dp[i - 1][j]

        # 최종 결과 반환
        return dp[len(s)][len(p)]


if __name__ == "__main__":
    sol = Solution()
    print(sol.isMatch("aab", "c*a*b"))
