import sys
input = sys.stdin.readline

K = int(input()) # 참외 개수
big = 1
small = 1
point = []
length = []

# count함수를 쓰기 위해 point와 length 리스트를 따로따로 만듦
for i in range(6):
    A, B = map(int, input().split())
    point.append(A)
    length.append(B)

# 방위는 1 ~ 4까지 있으므로 거기까지만 반복, point.index(i)는 중복일 시 가장 앞 인덱스를
# 가져와주므로 그대로 (idx + 1) % 6 연산을 써도 됨.
for i in range(1, 5):
    if point.count(i) == 1:
        big = big * length[point.index(i)]
    else:
        idx = point.index(i)
        if point[idx] == point[(idx + 2) % 6]:
            small = small * length[(idx + 1) % 6]

print(K * (big - small))