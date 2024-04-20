import sys
input = sys.stdin.readline

if __name__ == "__main__":
    val = int(input())

    for i in range(1, 10):
        print(f"{val} * {i} = {val * i}")