# 에라토스테네스의 체, N까지의 소수를 찾음
def Eratosthenes(n):
    primes = [True] * (n + 1)
    primes[0] = primes[1] = False
    for i in range(2, int(n**0.5) + 1):
        if primes[i]:
            primes[i * i :: i] = [False] * len(primes[i * i :: i])
    return primes


def Solution(n):
    # 선제조건
    if n <= 2 or n % 2 != 0:
        return 0

    # 소수 구하기
    primes = Eratosthenes(n)
    count = 0

    # 소수끼리의 합이라면 정답처리
    for i in range(2, n // 2 + 1):
        if primes[i] and primes[n - i]:
            count += 1

    return count


if __name__ == "__main__":
    import sys

    T = int(sys.stdin.readline())
    for i in range(T):
        N = int(sys.stdin.readline())
        print(Solution(N))
