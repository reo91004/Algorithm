import sys

input = sys.stdin.readline

if __name__ == "__main__":
    A, B = input().split()

    result = []

    for i in range(len(B) - len(A) + 1):  # 길이를 같게
        count = 0
        for j in range(len(A)):
            if A[j] != B[j + i]:
                count += 1
        result.append(count)

    print(min(result))
