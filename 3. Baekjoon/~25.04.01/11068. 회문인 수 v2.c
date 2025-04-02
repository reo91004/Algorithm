#include <stdbool.h>
#include <stdio.h>

#define MAX_DIGITS 64

bool is_palindrome_in_base(unsigned long long num, int base) {
    int digits[MAX_DIGITS];
    int len = 0;
    unsigned long long reversed = 0;
    unsigned long long original = num;

    // 주어진 base로 숫자 변환 및 역순 숫자 생성
    while (num) {
        int digit = num % base;
        digits[len++] = digit;
        reversed = reversed * base + digit;
        num /= base;
    }

    // 원래 숫자와 역순 숫자 비교
    return original == reversed;
}

int solution(unsigned long long T) {
    for (int base = 2; base <= 64; base++) {
        if (is_palindrome_in_base(T, base)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        unsigned long long T;
        scanf("%llu", &T);
        printf("%d\n", solution(T));
    }

    return 0;
}