num = int(input())
init = num
cnt = 0

while True:
    num = int((num % 10) * 10 + ((num / 10) + (num % 10)) % 10)
    cnt += 1

    if init == num:
        break

print(cnt)