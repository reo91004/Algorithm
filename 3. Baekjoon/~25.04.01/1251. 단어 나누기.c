#include <stdio.h>
#include <string.h>

#define MAX_LEN 51

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start; // 1. 시작 문자를 임시 변수에 저장
        *start++ = *end;    // 2. 끝 문자를 시작 위치에 복사하고, 시작 포인터를 오른쪽으로 이동
        *end-- = temp;      // 3. 임시 저장된 문자를 끝 위치에 복사하고, 끝 포인터를 왼쪽으로 이동
    }
}

void transform(const char *word, char *result, int i, int j) {
    int len = strlen(word);
    strncpy(result, word, i);
    reverse(result, result + i - 1);

    strncpy(result + i, word + i, j - i);
    reverse(result + i, result + j - 1);

    strcpy(result + j, word + j);
    reverse(result + j, result + len - 1);
}

int main() {
    char word[MAX_LEN], result[MAX_LEN], min_result[MAX_LEN];
    scanf("%s", word);

    int len = strlen(word);
    int first = 1; // 첫 번째 변환된 단어인지 여부

    for (int i = 1; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            transform(word, result, i, j);
            // 첫 번째 단어면 무조건 min_result로 복사
            if (first || strcmp(result, min_result) < 0) {
                strcpy(min_result, result);
                first = 0;
            }
        }
    }

    printf("%s\n", min_result);
    return 0;
}