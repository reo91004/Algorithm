import sys

input = sys.stdin.readline


def largest_run_number(digit, length):
    return int(str(digit) * length)


# 무조건 입력받으므로 이런식으로해도 가능
def decompose_to_run_numbers(N, K):
    result = []

    while K > 0:
        length = len(str(K))
        leading_digit = int(str(K)[0])
        run_number = largest_run_number(leading_digit, length)

        if run_number > K:
            run_number = largest_run_number(leading_digit - 1, length)

        result.append(run_number)
        K -= run_number

    return result


if __name__ == "__main__":
    T = int(input().strip())

    for _ in range(T):
        N, K = map(int, input().split())
        run_numbers = decompose_to_run_numbers(N, K)

        print(len(run_numbers))
        print(" ".join(map(str, run_numbers)))
