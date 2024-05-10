import sys
input = sys.stdin.readline

N, M = map(int, input().split())

dict = {}

for i in range(1, N + 1):
    word = input().strip()
    dict[i] = word
    dict[word] = i

for i in range(M):
    word = input().strip()
    if word.isdigit():
        print(dict[int(word)])
    else:
        print(dict[word])