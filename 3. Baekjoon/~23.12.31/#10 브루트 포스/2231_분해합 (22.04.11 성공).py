N = int(input())
res = 0

for i in range(1, N):
    val = i + sum((map(int, str(i)))) 

    if val == N:
        res = i
        break

print(res)