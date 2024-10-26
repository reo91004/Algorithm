if __name__ == "__main__":
    import sys
    from collections import deque

    input = sys.stdin.readline

    N, Q = map(int, input().split())
    dq = deque()

    # 포트 상태
    # -1이 그거 그ㅓ 안꽂힘, 0 이상이 꽂힘
    port_status = [-1] * (N + 1)

    # 남은 포트
    available_ports = deque(range(1, N + 1))

    action_count = 0

    for _ in range(Q):
        # 1이 꽂기, 2가 빼기
        # 행동, 포트
        t, i = map(int, input().split())
