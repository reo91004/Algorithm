from collections import deque


def Solution(queue):
    result = []

    # 첫 번째 풍선
    cur_index, move = queue.popleft()  # pop(0)과 같음
    result.append(cur_index)

    # 풍선이 남아 있는 동안 반복
    while queue:
        if move > 0:
            queue.rotate(
                -(move - 1)
            )  # 이미 한 번 터뜨렸으므로 회전된 상태이니 move - 1만큼 회전
        else:
            # 음수일 때는 왼쪽으로
            queue.rotate(-move)

        # 다음 풍선 터뜨리기
        cur_index, move = queue.popleft()
        result.append(cur_index)

    return result


if __name__ == "__main__":

    # 입력 받기
    N = int(input())
    balloons = list(map(int, input().split()))

    # 인덱스와 함께 저장
    queue = deque(enumerate(balloons, start=1))

    print(" ".join(map(str, Solution(queue))))
