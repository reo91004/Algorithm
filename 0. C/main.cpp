#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// queuestack 구조체
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} QueueStack;

void initQueueStack(QueueStack *qs) {
    qs->front = 0;
    qs->rear = -1;
}

void appendLeft(QueueStack *qs, int value) {
    if (qs->front == 0) {
        for (int i = qs->rear; i >= qs->front; i--) {
            qs->data[i + 1] = qs->data[i];
        }
        qs->rear++;
        qs->data[0] = value;
    } else {
        qs->front--;
        qs->data[qs->front] = value;
    }
}

void append(QueueStack *qs, int value) {
    qs->rear++;
    qs->data[qs->rear] = value;
}

int popLeft(QueueStack *qs) {
    int value = qs->data[qs->front];
    qs->front++;
    return value;
}

int *Solution(int N, int *A, int *B, int M, int *C) {
    QueueStack qs;
    initQueueStack(&qs);

    // 초기 큐 상태 설정
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) { // 큐인 경우에만 추가
            appendLeft(&qs, B[i]);
        }
    }

    int *results = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        append(&qs, C[i]);
        results[i] = popLeft(&qs);
    }

    return results;
}

int main() {
    int N, M;
    scanf("%d", &N);

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

    int *results = Solution(N, A, B, M, C);

    for (int i = 0; i < M; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");

    free(A);
    free(B);
    free(C);
    free(results);

    return 0;
}