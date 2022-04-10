T = int(input()) # 테스트 케이스

while T:
    H, W, N = map(int, input().split())
    floor = N % H
    room = N // H + 1

    if floor == 0:
         floor = H
    if N % H == 0:
         room -= 1

    print(f"{floor * 100 + room}")

    T -= 1