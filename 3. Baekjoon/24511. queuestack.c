#include <stdio.h>
#include <stdlib.h>

void *Solution(int N, int *A, int *B, int M, int *C) {
    for (int i = N - 1; M != 0 && i >= 0; --i) {
        if (A[i] == 0) { // 스택이 아닌 큐라면 역방향으로 출력
            printf("%d ", B[i]);
            --M;
        }
    }

    for (int i = 0; M != 0; ++i) {
        printf("%d ", C[i]);
        --M;
    }
}

int main() {
    int N, M;

    scanf("%d", &N);

    // 값들 입력받기
    int *A = (int *)malloc(N * sizeof(int));
    int *B = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    scanf("%d", &M);
    int *C = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &C[i]);
    }

    Solution(N, A, B, M, C);

    free(A);
    free(B);
    free(C);

    return 0;
}