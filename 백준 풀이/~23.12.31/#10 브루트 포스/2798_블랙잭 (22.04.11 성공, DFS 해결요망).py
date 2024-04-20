N, M = map(int, input().split())
arr = list(map(int, input().split()))
res = 0
for i in range(N):
   for j in range(i+1, N):
       for k in range(j+1, N):
           tmp = arr[i] + arr[j] + arr[k]

           if tmp <= M and res < tmp:
               res = tmp

print(res)