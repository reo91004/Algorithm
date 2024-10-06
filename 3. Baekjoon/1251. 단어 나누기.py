import sys


def solution(word):
    words = []

    for i in range(1, len(word)):
        for j in range(i + 1, len(word)):
            a = word[:i][::-1]
            b = word[i:j][::-1]
            c = word[j:][::-1]
            words.append(a + b + c)

    return min(words)


if __name__ == "__main__":
    input = sys.stdin.readline
    word = input().rstrip()

    print(solution(word))
