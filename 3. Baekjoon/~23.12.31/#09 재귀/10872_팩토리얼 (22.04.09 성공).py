def solution(N):
    if N <= 1:
        return 1
    else:
        return N * solution(N - 1)

N = int(input())
print(solution(N))