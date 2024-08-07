class Solution:
    def reverse(self, x: int) -> int:
        # 오류 범위 정의
        INT_MAX = 2**31 - 1
        INT_MIN = -(2**31)

        # 음수인지 확인
        sign = -1 if x < 0 else 1
        x = abs(x)

        # 숫자 뒤집고 부호 적용
        reversed_number = int(str(x)[::-1]) * sign

        # 오버플로우 검사
        if reversed_number < INT_MIN or reversed_number > INT_MAX:
            return 0

        return reversed_number


if __name__ == "__main__":
    sol = Solution()
    print(sol.reverse(123))  # 321
