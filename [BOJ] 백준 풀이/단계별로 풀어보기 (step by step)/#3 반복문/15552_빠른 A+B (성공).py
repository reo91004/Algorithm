import sys

val = int(sys.stdin.readline()) # input보다 처리속도가 빠름

for i in range(val):
    x, y = map(int, sys.stdin.readline().split())
    print(x + y)