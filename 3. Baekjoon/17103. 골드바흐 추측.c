#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 에라토스테네스의 체, N까지의 소수를 찾음
bool *Eratosthenes(int n) {
    bool *primes = (bool *)calloc(n + 1, sizeof(bool));
    for (int i = 2; i <= n; i++) {
        primes[i] = true;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int Solution(int n) {
    // 선제조건
    if (n <= 2 || n % 2 != 0) {
        return 0;
    }

    // 소수 구하기
    bool *primes = Eratosthenes(n);
    int count = 0;

    // 소수끼리의 합이라면 정답처리
    for (int i = 2; i <= n / 2; i++) {
        if (primes[i] && primes[n - i]) {
            count++;
        }
    }

    free(primes); // 동적 할당된 메모리 해제
    return count;
}

int main() {
    int T, N;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        printf("%d\n", Solution(N));
    }

    return 0;
}