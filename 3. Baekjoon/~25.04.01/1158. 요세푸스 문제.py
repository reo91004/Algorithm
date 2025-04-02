import sys

input = sys.stdin.readline


def solution(N, K):
    people = list(range(1, N + 1))
    result = []

    # 현재 위치
    index = 0

    while people:
        # K번째 사람의 인덱스 계산
        index = (index + K - 1) % len(people)
        # K번째 사람을 제거하고 결과에 추가
        result.append(people.pop(index))

    return result


if __name__ == "__main__":
    N, K = map(int, input().split())  # 사람 수, 양의 정수
    answer = solution(N, K)

    print("<" + ", ".join(map(str, answer)) + ">")
