import sys
input = sys.stdin.readline

if __name__ == "__main__":
    var = int(input())

    if var % 4 == 0 and (var % 100 != 0 or var % 400 == 0):
        print("1")
    else:
        print("0")