import sys

input = sys.stdin.readline

if __name__ == "__main__":
    scenario_num = 1

    while True:
        n = int(input().strip())
        if n == 0:
            break

        names = [input().strip() for _ in range(n)]
        counts = [0] * n  # 학생별 등장 횟수

        for _ in range(2 * n - 1):
            a, _ = input().strip().split()
            a = int(a) - 1  # 0부터 시작하도록 변환
            counts[a] ^= 1  # 등장 횟수를 XOR로 처리 (0 → 1 → 0)

        missing = counts.index(1)

        print(f"{scenario_num} {names[missing]}")
        scenario_num += 1
