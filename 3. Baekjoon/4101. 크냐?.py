import sys

if __name__ == "__main__":
    while True:
        M, N = map(int, input().split())

        if M == 0 and N == 0:
            break

        print("Yes") if M > N else print("No")
