import sys

input = sys.stdin.readline


if __name__ == "__main__":
    XA, YA, XB, YB, XC, YC = map(int, input().split())

    answer = 0.0
    # 기울기가 같다면 (외적 활용)
    if (XA - XB) * (YA - YC) == (YA - YB) * (XA - XC):
        answer = -1.0
    else:
        dist_AB = ((XA - XB) ** 2 + (YA - YB) ** 2) ** 0.5
        dist_BC = ((XB - XC) ** 2 + (YB - YC) ** 2) ** 0.5
        dist_CA = ((XC - XA) ** 2 + (YC - YA) ** 2) ** 0.5

        answer = (max(dist_AB, dist_BC, dist_CA) - min(dist_AB, dist_BC, dist_CA)) * 2

    print(answer)

# if (XA == XB == XC) or (YA == YB == YC) or ((XA != XB and XB != XC and XA != XC) and
#     (YA - YB) * (XA - XC) == (YA - YC) * (XA - XB)):
#     answer = -1.0
