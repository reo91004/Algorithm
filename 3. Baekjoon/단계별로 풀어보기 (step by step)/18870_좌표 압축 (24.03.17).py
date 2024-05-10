import sys

sys = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    inputArr = list(map(int, input().split()))
    index_dict = {value: index for index, value in enumerate(sorted(set(inputArr)))}

    print(*(index_dict[i] for i in inputArr))
