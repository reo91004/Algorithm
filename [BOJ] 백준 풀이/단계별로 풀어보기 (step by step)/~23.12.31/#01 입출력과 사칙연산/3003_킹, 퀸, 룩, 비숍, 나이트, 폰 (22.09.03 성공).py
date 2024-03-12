import sys
input = sys.stdin.readline

if __name__ == "__main__":
    chess = [1, 1, 2, 2, 2, 8]
    
    for i, v in enumerate(map(int, input().split())):
        print(chess[i] - v, end=" ")