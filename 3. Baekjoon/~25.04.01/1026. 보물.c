#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50
#define MAX_VALUE 100

int A[MAX_N];
int B_count[MAX_VALUE + 1] = {0};

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // 내림차순 정렬
}

long long solution(int N) {
    long long sum = 0;
    int B_index = 0;

    qsort(A, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        while (B_count[B_index] == 0) {
            B_index++;
        }
        sum += (long long)A[i] * B_index;
        B_count[B_index]--;
    }

    return sum;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int B;
    for (int i = 0; i < N; i++) {
        scanf("%d", &B);
        B_count[B]++;
    }

    long long result = solution(N);
    printf("%lld\n", result);

    return 0;
}