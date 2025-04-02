#include <stdio.h>

int main() {
    long long N;
    int L;

    scanf("%lld %d", &N, &L);

    // 길이를 L부터 100까지 증가시키며 반복
    for (long long length = L; length <= 100; length++) {
        // 시작 숫자를 계산 (등차수열 합 공식)
        // 혹시 모를 오버플로우를 위해 long long으로 형 변환
        long long start = (N - length * (length - 1) / 2) / length;

        if (start < 0)
            continue; // 시작 숫자가 음수면 다음 길이로

        // 계산된 시작 숫자로 등차수열의 합을 확인
        if (start * length + length * (length - 1) / 2 == N) {
            // 만족한다면 출력
            for (int i = 0; i < length; i++) {
                printf("%lld ", start + i);
            }
            printf("\n");
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}