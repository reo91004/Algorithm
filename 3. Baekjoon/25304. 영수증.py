if __name__ == "__main__":
    import sys

    input = sys.stdin.readline

    X = int(input())
    N = int(input())
    count = 0

    for i in range(N):
        a, b = map(int, input().split())
        count += a * b

    print(f"{'Yes' if count == X else 'No'}")
