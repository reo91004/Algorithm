import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = input().rstrip()
    number = "0123456789ABCDEF"

    decimal = 0
    for digit in N:
        decimal = decimal * 16 + number.index(digit)

    print(decimal)
