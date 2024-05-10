import sys
input = sys.stdin.readline

if __name__ == "__main__":
    res = 0
    
    X = int(input())
    
    for i in range(int(input())):
        a, b = map(int, input().split())
        res += a * b

    print("Yes") if X == res else print("No")