import sys
input = sys.stdin.readline

if __name__ == "__main__":
    A, B = input().split()
    A = int(A)

    print(A * int(B[2]))
    print(A * int(B[1]))
    print(A * int(B[0]))
    print(A * int(B))