import sys
input = sys.stdin.readline

if __name__ == "__main__":
    var = int(input())

    for i in range(var):
        x, y = map(int, input().split())
        print(x + y)