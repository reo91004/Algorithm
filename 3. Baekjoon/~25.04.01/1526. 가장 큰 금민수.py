import sys

input = sys.stdin.readline


def is_gumin_number(num):
    return all(c in "47" for c in str(num))


if __name__ == "__main__":
    N = int(input())

    # N부터 역순으로 금민수 탐색
    for i in range(N, 3, -1):
        if is_gumin_number(i):
            print(i)
            break
