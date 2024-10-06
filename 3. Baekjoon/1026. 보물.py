import sys


def Solution(A, B):
    A_sorted = sorted(A)
    # B의 값이 큰 순서대로 인덱스를 정렬
    sorted_indices = sorted(range(len(B)), key=lambda i: -B[i])

    # A_sorted의 작은 값부터 B의 큰 값에 대응
    assigned_A = [0] * len(A)
    for a, i in zip(A_sorted, sorted_indices):
        assigned_A[i] = a

    S = sum(a * b for a, b in zip(assigned_A, B))
    return S


if __name__ == "__main__":
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    result = Solution(A, B)
    print(result)
