import sys

sys.stdin = open("4. SW Expert/input.txt", "r")


def solution(number, k, memo):
    if k == 0:
        return int("".join(number))  # 교환 횟수가 0이면 현재 숫자를 정수로 반환

    state_key = (
        tuple(number),
        k,
    )  # 메모이제이션을 위한 상태 키 생성 (숫자 리스트, 남은 교환 횟수)
    if state_key in memo:
        return memo[state_key]

    max_value = int("".join(number))
    N = len(number)  # 숫자 리스트의 길이
    for i in range(N):
        for j in range(i + 1, N):
            number[i], number[j] = number[j], number[i]
            cur_value = solution(number, k - 1, memo)
            if cur_value > max_value:
                max_value = cur_value
            number[i], number[j] = number[j], number[i]

    memo[state_key] = max_value
    return max_value


T = int(input())

for test_case in range(1, T + 1):
    number, k = input().split()
    res = []
    number_list = list(number)
    memo = {}
    result = solution(number_list, int(k), memo)
    print(f"#{test_case} {result}")
