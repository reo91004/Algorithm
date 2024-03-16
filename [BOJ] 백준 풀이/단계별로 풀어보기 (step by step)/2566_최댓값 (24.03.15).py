import sys

sys = sys.stdin.readline


# 파이썬다운 방법
def findMaxIndex_Python():
    inputArr = []
    maxNum = float("-inf")

    for _ in range(9):
        tempArr = list(map(int, input().split()))
        inputArr.append(tempArr)

    maxNum, matrix = max(
        ((val, (i, j)) for i, row in enumerate(inputArr) for j, val in enumerate(row))
    )

    print(f"{maxNum}\n{matrix[0] + 1} {matrix[1] + 1}")


# 일반적인 방법, C언어 식
def findMaxIndex_C():
    maxNum = float("-inf")
    maxRow, maxCol = 0, 0

    for i in range(9):
        tempArr = list(map(int, input().split()))
        for j in range(9):
            if maxNum < tempArr[j]:
                maxNum = tempArr[j]
                maxRow, maxCol = i, j

    print(f"{maxNum}\n{maxRow + 1} {maxCol + 1}")


if __name__ == "__main__":
    findMaxIndex_Python()
