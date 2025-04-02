#include <stdio.h>

int sqaure(int a, int b, int c, int d, int e) {
    return a * a + b * b + c * c + d * d + e * e;
}

int main() {
    int a, b, c, d, e, f;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int result = sqaure(a, b, c, d, e);

    printf("%d\n", result % 10);
    return 0;
}