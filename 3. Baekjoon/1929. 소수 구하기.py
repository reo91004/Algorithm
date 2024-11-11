import sys

input = sys.stdin.readline


if __name__ == "__main__":
    # 숫자의 범위가 크므로 에라토스테네스의 체를 이용해야 한다는 직감
    M, N = map(int, input().split())

    # 에라토스테네스 체 선언, 0과 1은 소수가 아니므로 기본값 False
    arr = [False, False] + [True] * (N - 1)
    cnt = 2

    while cnt <= N:
        # 하나씩 지워나감
        # 2부터 시작해서, 해당 수는 소수로 두고 그 수의 배수들을 모두 False처리
        if arr[cnt]:
            for j in range(cnt + cnt, N + 1, cnt):
                if arr[j]:
                    arr[j] = False
        cnt += 1

    for i in range(M, N + 1):
        if arr[i]:
            print(i)
