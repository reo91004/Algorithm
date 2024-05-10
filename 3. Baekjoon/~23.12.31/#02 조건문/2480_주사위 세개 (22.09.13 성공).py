import sys
input = sys.stdin.readline

if __name__ == "__main__":
    a, b, c = map(int, input().split())
    
    if a == b and b == c: # 3개 동일
        print(10000 + (a * 1000))
    elif a == b or a == c: # 2개 동일 case 1
        print(1000 + (a * 100))
    elif b == c: # 2개 동일 case 2
        print(1000 + (b * 100))
    else: # 모두 다름
        print(max(a, b, c) * 100)