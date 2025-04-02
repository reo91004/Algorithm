#include <stdio.h>
#include <string.h>

int main() {
    char S[1001];
    int i;

    scanf("%s", S);
    scanf("%d", &i);

    printf("%c\n", S[i - 1]);

    return 0;
}