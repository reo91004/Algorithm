N = int(input())

for i in range(N):
    arr = list(map(int, input().split()))
    avg = sum(arr[1:]) / arr[0]
    count = 0

    for j in arr[1:]:
        if j > avg:
            count += 1
    
    rate = count / arr[0] * 100
    print(f"{rate:.3f}%")