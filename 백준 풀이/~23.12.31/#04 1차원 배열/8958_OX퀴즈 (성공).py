N = int(input())
for i in range(N):
    arr = list(input())
    sum = 0
    count = 1

    for j in arr:
        if j == 'O':
            sum += count
            count += 1
        else:
            count = 1
            
    print(sum)
