import sys
input = sys.stdin.readline

if __name__ == "__main__":
    var = int(input())
    sum = 0

    for i in range(var + 1):
        sum = sum + i

    print(sum)
