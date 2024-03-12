import sys
from collections import Counter
input = sys.stdin.readline

N = input()
arr = input().split()
M = input()
ans = input().split()

arr = Counter(arr)
print(' '.join(f'{arr[i]}' if i in arr else '0' for i in ans))