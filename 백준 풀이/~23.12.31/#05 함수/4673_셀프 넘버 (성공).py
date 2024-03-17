def non_self_num(num):
    sum = 0
    for i in str(num):
        sum += int(i)
    
    return int(num) + sum

number = []

for i in range(1, 10001):
    temp = non_self_num(i)
    number.append(temp)

for i in range(1, 10001):
    if i in number:
        pass
    else:
        print(i)
