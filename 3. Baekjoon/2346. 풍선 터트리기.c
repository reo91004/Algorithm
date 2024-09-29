#include <stdio.h>

#define MAX 1000

typedef struct {
    int idx;    // 풍선의 원래 인덱스
    int value;  // 풍선 안에 적힌 수
    int prev;   // 이전 풍선의 인덱스
    int next;   // 다음 풍선의 인덱스
    int popped; // 풍선이 터졌는지 여부 (0: 터지지 않음, 1: 터짐)
} Balloon;

void Solution(Balloon *balloons, int N) {
    // 풍선 초기화
    for (int i = 1; i <= N; ++i) {
        balloons[i].idx = i;
        scanf("%d", &balloons[i].value);
        balloons[i].popped = 0;
        balloons[i].prev = (i == 1) ? N : i - 1;
        balloons[i].next = (i == N) ? 1 : i + 1;
    }

    int current = 1; // 첫 번째 풍선부터 시작

    for (int count = 0; count < N; ++count) {
        printf("%d ", balloons[current].idx);
        balloons[current].popped = 1; // 현재 풍선을 터뜨림

        if (count == N - 1)
            break; // 마지막 풍선이면 종료

        int move = balloons[current].value;

        // 현재 풍선을 리스트에서 제거
        int prev = balloons[current].prev;
        int next = balloons[current].next;
        balloons[prev].next = next;
        balloons[next].prev = prev;

        // 이동할 방향에 따라 다음 풍선으로 이동
        if (move > 0) {
            // 오른쪽으로 이동
            for (int i = 0; i < move; ++i) {
                current = balloons[current].next;
            }
        } else {
            // 왼쪽으로 이동
            for (int i = 0; i < -move; ++i) {
                current = balloons[current].prev;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Balloon balloons[MAX + 1];

    Solution(balloons, N);

    return 0;
}