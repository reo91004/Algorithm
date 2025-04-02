#include <stdio.h>

int main() {
    int L;
    char str[51];
    long long res = 0, r = 1;
    const long long M = 1234567891; // 모듈러 값

    scanf("%d", &L);
    scanf("%s", str);

    for (int i = 0; i < L; ++i) {
        res = (res + (str[i] - 96) * r) % M; // 모듈러 연산 적용
        r = (r * 31) % M;                    // r 값도 모듈러 연산 적용
    }

    printf("%lld\n", res);

    return 0;
}