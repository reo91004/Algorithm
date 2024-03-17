#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num; // 원소 개수
    int max; // 집합 크기
    int *set;
} Set;

void initSet(Set *s, int N) {
    s->num = 0;
    s->max = N;
    s->set = (int *)malloc(N * sizeof(int));
}

int isMember(Set *s, int num) {
    for (int i = 0; i < s->max; i++)
        if (s->set[i] == num) return 1;
    return 0;
}

void addSet(Set *s, int num) {
    if (!isMember(s, num) && s->num < s->max) s->set[s->num++] = num;
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() { 
    int N = 0; 
    scanf("%d", &N);

    Set s;
    initSet(&s, N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    qsort(arr, N, sizeof(int), compare);

    for (int i = 0; i < N; i++)
        printf("%d", arr[i]);
}
