from collections import deque
import sys

input = sys.stdin.readline


def Solution(n, positions):
    # 덱 생성
    queue = deque(range(1, n + 1))
    count = 0

    for pos in positions:
        index = queue.index(pos)

        # 왼쪽으로 이동하는 것이 더 가까운 경우
        if index <= len(queue) // 2:
            count += index
            queue.rotate(-index)
        # 오른쪽으로 이동하는 것이 더 가까운 경우
        else:
            count += len(queue) - index
            queue.rotate(len(queue) - index)

        # 원소 제거
        queue.popleft()

    return count


if __name__ == "__main__":
    N, M = map(int, input().split())
    positions = list(map(int, input().split()))

    print(Solution(N, positions))
