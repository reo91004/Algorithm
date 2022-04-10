def hanoi(N, start, mid, end):
    if N == 1:
        print(start, end)
    else:
        hanoi(N - 1, start, end, mid)
        print(start, end)
        hanoi(N - 1, mid, start, end)

N = int(input())
print((1 << N) - 1)
hanoi(N, 1, 2, 3)