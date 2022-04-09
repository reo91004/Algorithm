xset = []
yset = []

for i in range(3):
    x, y = map(int, input().split())
    xset.append(x)
    yset.append(y)

for i in xset:
    if xset.count(i) == 1:
        print(i, end=" ")
        break

for i in yset:
    if yset.count(i) == 1:
        print(i)