def han(num):
    count = 0
    for i in range(1, num+1):
        temp = list(map(int, str(i)))
        if i < 100:
            count += 1
        elif temp[0] - temp[1] == temp[1] - temp[2]:
            count += 1
    
    return count
    
num = int(input())
print(han(num))
