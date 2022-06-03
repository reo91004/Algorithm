import sys
input = sys.stdin.readline

while True:
    arr = list(map(int, input().split()))
    if sum(arr) == 0:
        break

    l = max(arr)
    arr.remove(l)

    if arr[0] ** 2 + arr[1] ** 2 == l ** 2:
        print("right")
    else:
        print("wrong")