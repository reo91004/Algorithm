T = int(input())

for i in range(T):
    R, text = input().split()
    
    for i in text:
        print(int(R) * i, end='')

    print('') 