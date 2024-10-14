import sys

input = sys.stdin.readline

if __name__ == "__main__":
    text = input().rstrip()
    words = text.split()

    reversed_words = [word[::-1] for word in words]  # 각 단어를 뒤집습니다.

    result = " ".join(reversed_words)

    print(result)
