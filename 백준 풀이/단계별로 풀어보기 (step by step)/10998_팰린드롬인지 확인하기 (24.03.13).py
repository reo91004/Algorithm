import sys

input = sys.stdin.readline

if __name__ == "__main__":
    text = input().rstrip()

    print(1) if text == text[::-1] else print(0)
