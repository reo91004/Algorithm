import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
M = int(input())
arr2 = list(map(int, input().split()))

arr.sort()

def binary_search(arr, key, N):
    start = 0
    end = N - 1

    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == key:
            return True
        elif arr[mid] < key:
            start = mid + 1
        else:
            end = mid - 1

    return False

for i in arr2:
    if binary_search(arr, i, N):
        print(1, end=" ")
    else:
        print(0, end=" ")