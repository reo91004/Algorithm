#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int multiply(int x, int y)
{
    if (y == 0) return 0;
    int z = multiply(x, y / 2);

    if (y % 2 == 0)
        return 2 * z;
    else
        return x + 2 * z;
}

int main()
{
    int x, y;
    printf("두 정수 입력 : ");
    scanf("%d %d", &x, &y);

    int result = multiply(x, y);

    printf("%d", result);

    return 0;
}