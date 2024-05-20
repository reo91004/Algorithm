import sys

# 테스트용 파일 입력
sys.stdin = open("4. SW Expert/input.txt", "r")


def solution(numbers, cnt, res):
    temp = "".join(numbers)

    # 메모제이션
    if cnt in res and int(temp) in res[cnt]:
        return
    else:
        # 현재 상태를 추가
        if cnt not in res:
            res[cnt] = set()  # 처음 생성이면 집합으로
        res[cnt].add(int(temp))

    # 교환 횟수 0
    if cnt == 0:
        return

    N = len(numbers)

    # 위치 교환
    for i in range(N):
        for j in range(i + 1, N):
            numbers[i], numbers[j] = numbers[j], numbers[i]
            solution(numbers, cnt - 1, res)
            numbers[i], numbers[j] = numbers[j], numbers[i]


T = int(input())

for t in range(1, T + 1):
    temp, cnt = input().split()

    numbers = list(temp)
    res = {}  # 결과 저장 딕셔너리

    solution(numbers, int(cnt), res)

    print("#{} {}".format(t, max(res[0])))
