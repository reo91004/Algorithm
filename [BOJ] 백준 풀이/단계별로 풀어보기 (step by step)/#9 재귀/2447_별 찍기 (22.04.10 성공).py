def solution(arr):
    tmparr = []
    length = len(arr) # N 크기

    # 새로이 그려야 하는데, 행과 열이 3개씩 더 있으므로 3을 곱한 만큼 반복
    for i in range(3 * length):
        if i // length == 1: # 중앙에 공백을 채우기 위한 장치 (N = 9일 때 3, 4, 5 공백)
            tmparr.append(arr[i % length] + " " * length + arr[i % length])
        else: # 이외에는 그냥 출력
            tmparr.append(arr[i % length] * 3)

    return tmparr
 
arr = ["***","* *","***"]
N = int(input())

# 그리기
while N != 3:
    arr = solution(arr)
    N = N // 3

# 결과 출력
for i in arr:
    print(i)