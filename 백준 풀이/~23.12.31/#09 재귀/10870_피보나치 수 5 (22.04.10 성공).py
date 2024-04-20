def solution(N):
    if N == 0:
        return 0
    if N == 1:
        return 1
    else:
        return solution(N - 1) + solution(N - 2)

N = int(input())
print(solution(N))