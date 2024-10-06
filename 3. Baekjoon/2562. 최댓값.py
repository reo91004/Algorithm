if __name__ == "__main__":
    import sys

    input = sys.stdin.readline

    res = []
    for i in range(9):
        res.append(int(input()))

    val = max(res)
    print(val)
    print(res.index(val) + 1)
