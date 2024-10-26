if __name__ == "__main__":
    import sys

    input = sys.stdin.readline

    N = int(input())

    tag_count = {}

    for _ in range(N):
        data = input().split()
        t = int(data[1])
        tags = data[2:]

        # 빈도 기록
        for tag in tags:
            # 만약 tag가 이미 존재하면 +1
            if tag in tag_count:
                tag_count[tag] += 1
            # 없다면 생성
            else:
                tag_count[tag] = 1

    # 가장 많이 등장한 태그의 빈도 찾기
    max_freq = max(tag_count.values())

    # 가장 많이 등장한 태그가 여러 개 있는지 확인
    result = [tag for tag, count in tag_count.items() if count == max_freq]

    # 여러개면 하나 -1 아니면 출력
    print(-1) if len(result) > 1 else print(result[0])
