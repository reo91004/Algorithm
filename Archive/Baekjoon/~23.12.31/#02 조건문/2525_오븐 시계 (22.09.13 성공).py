import sys
input = sys.stdin.readline

if __name__ == "__main__":
    A, B = map(int, input().split())
    var = int(input())

    A = (A + (B + var) // 60) % 24
    B = (B + var) % 60

    print(A, B)