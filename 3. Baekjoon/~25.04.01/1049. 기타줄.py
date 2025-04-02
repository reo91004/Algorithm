import sys

input = sys.stdin.readline

if __name__ == "__main__":
    # N : 기타줄의 개수, M : 브랜드의 수
    N, M = map(int, input().split())
    brand = []
    res = 0

    for _ in range(M):
        cost_6, cost_1 = map(int, input().split())
        brand.append([cost_6, cost_1])

    # 모든 브랜드 중 패키지 최소 가격과 낱개 최소 가격 선택
    brand_cost_6 = min(brand, key=lambda x: x[0])[0]  # 패키지(6개) 최소 가격
    brand_cost_1 = min(brand, key=lambda x: x[1])[1]  # 낱개 최소 가격

    # 기타줄이 6개 미만
    if N < 6:
        # 패키지 구매 vs 낱개 구매 중 선택
        res = min(brand_cost_6, brand_cost_1 * N)
    # 기타줄이 6개 이상
    else:
        tmp_6 = N // 6  # 패키지 수
        tmp_1 = N % 6  # 낱개 수

        # 패키지로만 구매 vs 낱개로만 구매 중 선택
        res = min(brand_cost_6 * tmp_6, brand_cost_1 * tmp_6 * 6)
        # 남은 낱개에 대해
        # 패키지 구매 vs 낱개 구매 중 선택
        res += min(brand_cost_6, brand_cost_1 * tmp_1)

    print(res)
