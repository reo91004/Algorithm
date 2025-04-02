import sys

input = sys.stdin.readline

if __name__ == "__main__":
    line = list(input().rstrip())
    line = sorted(line, reverse=True)

    print(f'{"".join(line)}')
