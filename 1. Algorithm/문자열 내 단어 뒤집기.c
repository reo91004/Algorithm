#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000001

void reverse_string(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char text[MAX_LENGTH];

    // 입력받기, scanf는 공백때매 안댐
    fgets(text, sizeof(text), stdin);

    reverse_string(text);

    printf("%s\n", text);

    return 0;
}