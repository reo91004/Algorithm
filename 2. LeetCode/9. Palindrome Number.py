class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            x = str(x)
            return x == x[::-1]


if __name__ == "__main__":
    sol = Solution()
    print(sol.isPalindrome(10))  # True
