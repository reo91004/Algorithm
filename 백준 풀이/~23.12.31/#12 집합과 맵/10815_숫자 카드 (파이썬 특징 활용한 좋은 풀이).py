import sys
input = sys.stdin.readline

input()
arr = set(input().split())
input()
print(*[1 if i in arr else 0 for i in input().split()])