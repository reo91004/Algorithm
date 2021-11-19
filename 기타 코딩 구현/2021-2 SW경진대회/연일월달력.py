T = int(input())

for i in range(1, T + 1):
    temp = input()

    year = temp[0:4]
    months = temp[4:6]
    dates = temp[6:8]

    month = int(months)
    date = int(dates)

    if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12:
        if date >= 1 and date <= 31:
            print(f"#{i} {year}/{months}/{dates}")
        else:
            print(f"#{i} -1")
    elif month == 4 or month == 6 or month == 9 or month == 11:
        if date >= 1 and date <= 30:
            print(f"#{i} {year}/{months}/{dates}")
        else:
            print(f"#{i} -1")
    elif month == 2:
        if date >= 1 and date <= 28:
            print(f"#{i} {year}/{months}/{dates}")
        else:
            print(f"#{i} -1")
    else:
        print(f"#{i} -1")