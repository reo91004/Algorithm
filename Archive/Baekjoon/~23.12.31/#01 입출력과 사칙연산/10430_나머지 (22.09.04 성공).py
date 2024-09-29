import sys
input = sys.stdin.readline

if __name__ == "__main__":
    A, B, C = map(int, input().split())
    
    print((A + B) % C, ((A % C)+(B % C)) % C, (A * B) % C, ((A % C)*(B % C)) % C, sep="\n")
