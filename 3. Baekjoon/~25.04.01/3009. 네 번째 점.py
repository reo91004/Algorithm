import sys

input = sys.stdin.readline

if __name__ == "__main__":
    x_coords = []
    y_coords = []

    for i in range(3):
        x, y = map(int, input().split())
        x_coords.append(x)
        y_coords.append(y)

    # x 좌표중 하나만 있는 좌표와, y 좌표중 하나만 있는 좌표만 출력하면 됨
    for i in x_coords:
        if x_coords.count(i) == 1:
            print(i, end=" ")
            break

    for i in y_coords:
        if y_coords.count(i) == 1:
            print(i)
