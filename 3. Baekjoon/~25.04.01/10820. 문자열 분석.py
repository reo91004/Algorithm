import sys

input = sys.stdin.readline

if __name__ == "__main__":
    while True:
        line = input().rstrip("\n")

        if not line:
            break

        # 소문자, 대문자, 숫자, 공백
        lower, upper, digit, blank = 0, 0, 0, 0
        for l in line:
            if l.islower():
                lower += 1
            elif l.isupper():
                upper += 1
            elif l.isdigit():
                digit += 1
            elif l.isspace():
                blank += 1

        print(lower, upper, digit, blank)
