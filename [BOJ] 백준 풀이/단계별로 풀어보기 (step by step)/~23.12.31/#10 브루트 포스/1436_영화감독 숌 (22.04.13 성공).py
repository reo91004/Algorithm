N = int(input())
val = 0
start = 666

while True:
    if '666' in str(start):
        val += 1
    if val == N:
        print(start)
        break
    
    start += 1