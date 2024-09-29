#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 64 // 64진법

bool is_palindrome(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int *to_base_n(long long T, int base, int *size) {
    int *digits = (int *)malloc(MAX_DIGITS * sizeof(int));
    *size = 0;
    while (T) {
        digits[*size] = T % base;
        T /= base;
        (*size)++;
    }
    return digits;
}

int Solution(long long T) {
    for (int base = 2; base <= 64; base++) {
        int size;
        int *digits = to_base_n(T, base, &size);
        if (is_palindrome(digits, size)) {
            free(digits);
            return 1;
        }
        free(digits);
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        long long T;
        scanf("%lld", &T);
        printf("%d\n", Solution(T));
    }

    return 0;
}