def Solution(N, A):
    indexed_A = list(enumerate(A))

    # 원소 값을 기준으로 정렬
    indexed_A.sort(key=lambda x: x[1])

    # 새로운 인덱스 할당
    new_A = {}
    for new_index, (original_index, value) in enumerate(indexed_A):
        new_A[original_index] = new_index

    # P 배열 구성
    P = [new_A[i] for i in range(N)]

    return P


if __name__ == "__main__":
    import sys

    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    result = Solution(N, A)
    print(*result)
