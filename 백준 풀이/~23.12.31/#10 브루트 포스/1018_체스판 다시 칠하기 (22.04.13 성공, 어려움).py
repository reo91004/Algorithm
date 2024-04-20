N, M = map(int, input().split())
arr = []
res = []

for i in range(N):
    arr.append(input())

for i in range(N - 7):
    for j in range(M - 7):
        cnt1 = 0
        cnt2 = 0
        
        for x in range(i, i + 8):
            for y in range(j, j + 8):
                if (x + y) % 2 == 0:
                    if arr[x][y] != 'W': cnt1 += 1  
                    if arr[x][y] != 'B': cnt2 += 1
                else :
                    if arr[x][y] != 'W': cnt2 += 1
                    if arr[x][y] != 'B': cnt1 += 1

        res.append(cnt1)
        res.append(cnt2)

print(min(res))