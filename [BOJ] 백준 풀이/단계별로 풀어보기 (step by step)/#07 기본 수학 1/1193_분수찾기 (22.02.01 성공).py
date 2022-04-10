N = int(input())

val = 1
while N > val:
    N -= val
    val += 1

if val % 2 == 0: # 짝수일 시
    print(f"{N}/{val + 1 - N}")
else:
    print(f"{val + 1 - N}/{N}")