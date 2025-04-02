import sys

input = sys.stdin.readline

if __name__ == "__main__":
    A, B = input().split()

    sum_A = sum(int(a) for a in A)
    sum_B = sum(int(b) for b in B)

    result = sum_A * sum_B

    print(result)
