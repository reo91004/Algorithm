#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *indices; // 각 값의 현재 인덱스를 저장
    int front;    // 큐의 front 인덱스
    int size;     // 현재 큐의 크기
} Queue;

Queue *createQueue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->indices = (int *)malloc((n + 1) * sizeof(int));
    q->front = 0;
    q->size = n;
    for (int i = 1; i <= n; i++) {
        q->indices[i] = 1; // 초기 인덱스 설정
    }
    return q;
}

void destroyQueue(Queue *q) {
    free(q->indices);
    free(q);
}

int min_operations(int n, int m, int *positions) {
    Queue *q = createQueue(n);
    int operations = 0;

    for (int i = 0; i < m; i++) {
        int target = positions[i];
        int current_pos = q->indices[target];
        int distance = (current_pos - q->front + q->size) % q->size; // 시계방향 거리 계산

        // 왼쪽과 오른쪽 중 더 가까운 방향으로 이동
        operations += (distance <= q->size / 2) ? distance : q->size - distance;

        // 큐 상태 업데이트
        for (int j = 1; j <= n; j++) {
            if (q->indices[j] < current_pos) {
                // current_pos 앞에 있는 모든 원소들의 인덱스를 1 증가
                // 이는 target 원소를 제거하고 나머지 원소들을 한 칸씩 앞으로 당기는 효과
                q->indices[j] = (q->indices[j] + 1) % q->size;
            }
            // current_pos 뒤에 있는 원소들은 그대로 유지 (상대적 위치 변화 없음)
        }

        // target 원소를 큐의 맨 앞(front)으로 이동
        q->indices[target] = q->front;

        // front를 다음 위치로 이동 (다음 원소를 가리키도록)
        q->front = (q->front + 1) % q->size;

        // 큐의 크기를 1 감소 (target 원소를 제거했으므로)
        q->size--;
    }

    destroyQueue(q);
    return operations;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *positions = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &positions[i]);
    }

    printf("%d\n", min_operations(n, m, positions));

    free(positions);
    return 0;
}