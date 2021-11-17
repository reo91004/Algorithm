N, X = map(int, input().split())
val = list(map(int, input().split()))

for i in range(N):
    if X > val[i]:
        print(f"{val[i]} ", end="")