class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()  # 공백 제거
        if not s:
            return 0

        sign = 1
        res = 0
        int_max, int_min = 2**31 - 1, -(2**31)

        if s[0] in "+-":
            sign = -1 if s[0] == "-" else 1
            s = s[1:]

        for char in s:
            if not char.isdigit():
                break
            res = res * 10 + int(char)
            # 성능 향상을 위해 범위를 넘었을 경우 즉시 리턴
            if sign == 1 and res > int_max:
                return int_max
            if sign == -1 and res * sign < int_min:
                return int_min

        return max(int_min, min(sign * res, int_max))


if __name__ == "__main__":
    sol = Solution()
    print(sol.myAtoi(" -42"))
