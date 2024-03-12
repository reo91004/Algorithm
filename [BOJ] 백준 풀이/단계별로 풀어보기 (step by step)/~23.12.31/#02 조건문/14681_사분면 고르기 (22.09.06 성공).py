import sys
input = sys.stdin.readline

if __name__ == "__main__":
    x = int(input()); y = int(input())

    if x > 0:
        print(1 if y > 0 else 4)
    else:
        print(2 if y > 0 else 3)