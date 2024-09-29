def is_palindrome(l):
    return l == l[::-1]


def to_base_n(T, base):
    digits = []
    while T:
        digits.append(int(T % base))
        T //= base
    return digits


def Solution(T):
    for base in range(2, 65):
        if is_palindrome(to_base_n(T, base)):
            return 1
    return 0


if __name__ == "__main__":
    import sys

    N = int(sys.stdin.readline())

    for i in range(N):
        T = int(input())
        print(Solution(T))
