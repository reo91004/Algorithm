import sys
input = sys.stdin.readline

a, b = map(int, input().split())

while a != 0 and b != 0:
    if b % a == 0:
        print("factor")
    elif a % b == 0: 
        print("multiple")
    else:
        print("neither")

    a, b = map(int, input().split())