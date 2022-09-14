import sys
input = sys.stdin.readline

if __name__ == "__main__":
    for i in range(int(input())):
        x, y = map(int, input().split())
        print(f"Case #{i+1}: {x + y}")
