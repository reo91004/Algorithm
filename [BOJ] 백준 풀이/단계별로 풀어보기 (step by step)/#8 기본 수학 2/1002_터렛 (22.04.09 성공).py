import math

T = int(input())

for i in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())

    # 두 원의 중심 사이의 거리
    dist = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
    cmp1 = abs(r1 - r2)
    cmp2 = r1 + r2

    if dist == 0: # 두 점 사이의 거리가 0이고
        if cmp1 == 0:  # 반지름의 차도 0이면 있을 수 있는 곳이 무한대이다. 그림을 그려보자.
            print(-1)
        else:                     
            print(0)
    else:        
        if cmp1 == dist or cmp2 == dist:
            print(1)
        elif (cmp1 < dist and dist < cmp2):
            print(2)
        else:
            print(0)
