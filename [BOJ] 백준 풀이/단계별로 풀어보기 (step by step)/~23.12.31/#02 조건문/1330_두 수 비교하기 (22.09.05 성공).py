import sys
input = sys.stdin.readline

if __name__ == "__main__":
    A,B = map(int, input().split())
    print(">") if A > B else print("<") if A < B else print("==")