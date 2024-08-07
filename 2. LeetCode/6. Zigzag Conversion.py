from typing import List


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        res = ["" for _ in range(numRows)]
        index = 0
        direction = 1
        for c in s:
            res[index] += c
            if index == 0:
                direction = 1
            elif index == numRows - 1:
                direction = -1
            index += direction

        return "".join(res)


if __name__ == "__main__":
    sol = Solution()
    print(sol.convert("PAYPALISHIRING", 3))
    print(sol.convert("PAYPALISHIRING", 4))
    print(sol.convert("A", 1))
