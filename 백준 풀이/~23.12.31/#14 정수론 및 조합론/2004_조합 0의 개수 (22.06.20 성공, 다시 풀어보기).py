import sys
input = sys.stdin.readline

N, M = map(int, input().split())

def solution(n, k):
    cnt = 0
    while n > 1:
        n //= k
        cnt += n

    return cnt

five = solution(N, 5) - solution(M, 5) - solution(N - M, 5)
two = solution(N, 2) - solution(M, 2) - solution(N - M, 2)

print(min(five, two))