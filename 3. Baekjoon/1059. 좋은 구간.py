import sys

input = sys.stdin.readline


def solution(S: list, n: int) -> int:
    A, B = 0, 0

    # A와 B 찾기
    for s in S:
        if s <= n:
            A = s
        if s >= n:
            B = s
            break

    # 만약 A와 B가 같으면 (n이 범위에 포함된 경우) 0을 반환
    return 0 if A == n or B == n else (n - A) * (B - n) - 1

    # result = 0
    # # 가능한 시작점과 끝점 구간을 모두 탐색
    # for start in range(A + 1, n + 1):  # n을 포함하는 시작점
    #     for end in range(n, B):  # n을 포함하는 끝점
    #         if start < end:
    #             result += 1

    # return result


if __name__ == "__main__":
    L = int(input())
    S = list(map(int, input().rstrip().split()))
    n = int(input())

    print(solution(sorted(S), n))
