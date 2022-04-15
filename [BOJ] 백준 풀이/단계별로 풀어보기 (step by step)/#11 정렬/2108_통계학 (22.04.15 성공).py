from collections import Counter

N = int(input())
arr = []

for _ in range(N):
    num = int(input())
    arr.append(num)

arr.sort()

cnt = Counter(arr).most_common(2)

print(round(sum(arr) / N)) # 산술평균
print(arr[(N - 1) / 2]) # 중앙값
if N > 1: # 최빈값
    if cnt[0][1] == cnt[1][1]:
        print(cnt[1][0])
    else:
        print(cnt[0][0])
else:
    print(cnt[0][0])
print(max(arr) - min(arr)) # 최대 최소 차이
