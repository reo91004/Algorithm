import sys

input = sys.stdin.readline


if __name__ == "__main__":
    day = 0
    month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

    # 월, 일
    x, y = map(int, input().split())

    # x월까지 순회해서 day 카운트
    for i in range(x - 1):
        day += month[i]

    # mod 연산으로 요일 탐색
    day = (day + y) % 7

    print(week[day])
