import sys
from decimal import Decimal, ROUND_HALF_UP

input = sys.stdin.readline

if __name__ == "__main__":
    words = input().strip().split()

    ph = sum(word.count(c) for word in words for c in "HAPY")
    pg = sum(word.count(c) for word in words for c in "SAD")

    if ph == 0 and pg == 0:
        print("50.00")
    else:
        value = 100 * ph / (ph + pg)
        rounded_value = Decimal(value).quantize(Decimal("0.01"), rounding=ROUND_HALF_UP)
        print(f"{rounded_value:.2f}")
