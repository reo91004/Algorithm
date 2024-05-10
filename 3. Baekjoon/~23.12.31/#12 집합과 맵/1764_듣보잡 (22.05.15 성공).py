import sys
input = sys.stdin.readline

N, M = map(int, input().split())
N_list = [input().strip() for i in range(N)]
M_list = [input().strip() for i in range(M)]

res = sorted(list(set(N_list) & set(M_list)))

print(len(res))

for i in res:
    print(i)