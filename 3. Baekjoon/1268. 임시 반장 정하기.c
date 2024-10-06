#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000
#define GRADES 5

int students[MAX_STUDENTS][GRADES];
int student_counts[MAX_STUDENTS] = {0};

// 가장 많은 학생과 같은 반이었던 학생을 찾는 함수
int solution(int N) {
    int max_count = 0;
    int president = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // 두 학생이 같은 반이었는지 확인
            for (int grade = 0; grade < GRADES; grade++) {
                if (students[i][grade] == students[j][grade]) {
                    // 같은 반이었다면 두 학생의 카운트를 증가
                    student_counts[i]++;
                    student_counts[j]++;
                    break;
                }
            }
        }
    }

    // 가장 많은 학생과 같은 반이었던 학생 찾기 (동일한 경우 가장 높은 번호)
    for (int i = 0; i < N; i++) {
        if (student_counts[i] > max_count) {
            max_count = student_counts[i];
            president = i + 1; // 학생 번호는 1부터 시작
        }
    }

    return president;
}

int main() {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < GRADES; j++) {
            scanf("%d", &students[i][j]);
        }
    }

    int result = solution(N);
    printf("%d\n", result);

    return 0;
}
