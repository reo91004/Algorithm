import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    for _ in range(N // 4):
        print("long ", end="")

    print("int")
