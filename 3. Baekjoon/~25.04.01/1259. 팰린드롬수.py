import sys

input = sys.stdin.readline

if __name__ == "__main__":
    while True:
        N = input().rstrip()

        if N == "0":
            break

        print("yes") if N == N[::-1] else print("no")
