#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int resArr[100][100] = {0}; // 2차원 배열 선언 및 초기화

    for (int k = 0; k < N; k++) {
        int x, y;
        scanf("%d %d", &x, &y);

        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                resArr[i][j] = 1;
            }
        }
    }

    int total_sum = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            total_sum += resArr[i][j];
        }
    }

    printf("%d\n", total_sum);

    return 0;
}
