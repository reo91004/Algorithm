#include <stdio.h>

long long factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

long long Solution(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    printf("%lld", Solution(N, K));
    return 0;
}