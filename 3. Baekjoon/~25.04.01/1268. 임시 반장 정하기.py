import sys

input = sys.stdin.readline


def solution(N, student):
    student_count = [0 for _ in range(N)]

    for i in range(N):  # N번 학생에 대해 반복
        # 두 학생이 1학년부터 5학년까지 중 한 번이라도 같은 반이었는지 확인
        for j in range(i + 1, N):
            if any(student[i][grade] == student[j][grade] for grade in range(5)):
                student_count[i] += 1
                student_count[j] += 1

    return student_count.index(max(student_count)) + 1


if __name__ == "__main__":
    N = int(input())

    student = []
    for _ in range(N):
        student.append(list(map(int, input().split())))

    print(solution(N, student))
