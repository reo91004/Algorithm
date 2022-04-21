T = int(input())

for i in range(1, T + 1):
    card = input()

    MMs = card[0:2]
    YYs = card[2:4]

    MM = int(MMs)
    YY = int(YYs)

    if (MM <= 12 and MM >= 1) and (YY <= 12 and YY >= 1):
        print(f"#{i} AMBIGUOUS")
    elif (YY >= 12 or YY <= 1) and (MM <= 12 and MM >= 1):
        print(f"#{i} MMYY")
    elif (MM >= 12 or MM <= 1) and (YY <= 12 and YY >= 1):
        print(f"#{i} YYMM")
    else:
        print(f"#{i} NA")