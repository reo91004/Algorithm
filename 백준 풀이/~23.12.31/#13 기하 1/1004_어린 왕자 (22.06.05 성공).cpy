import sys
input = sys.stdin.readline

T = int(input())
for i in range(T):
    cnt = 0
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    for i in range(n):
        x, y, r = map(int, input().split())
        dist1 = (((x1 - x) ** 2) + ((y1 - y) ** 2))
        dist2 = (((x2 - x) ** 2) + ((y2 - y) ** 2))
        radius = r * r
        if dist1 < radius and dist2 < radius:
            continue
        elif dist1 < radius or dist2 < radius:
            cnt += 1
    print(cnt)