import sys

if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))

    count = 0
    i = 0

    while i < N - 1:
        # 충족하면 다음으로 이동
        if abs(A[i + 1] - A[i]) >= M:
            i += 1
        else:
            j = i
            # 해당 구간 끝
            while j < N - 1 and abs(A[j + 1] - A[j]) < M:
                j += 1
            # 구간 길이
            L = j - i + 1

            # 최소시행횟수 L // 2
            count += L // 2
            # 인덱스 이동
            i = j + 1

    print(count)
