import sys
input = sys.stdin.readline

if __name__ == "__main__":
    var = int(input())

    for i in range(var):
        x, y = map(int, input().split())
        print(f"Case #{i+1}: {x} + {y} = {x + y}")