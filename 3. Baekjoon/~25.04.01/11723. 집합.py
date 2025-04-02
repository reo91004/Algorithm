import sys

input = sys.stdin.readline
write = sys.stdout.write

if __name__ == "__main__":
    M = int(input())
    S = set()  # 공집합

    for _ in range(M):
        command = input().strip().split()
        oper = command[0]

        if oper == "add":
            S.add(int(command[1]))
        elif oper == "remove":
            S.discard(int(command[1]))
        elif oper == "check":
            write("1\n" if int(command[1]) in S else "0\n")  # 빠른 출력
        elif oper == "toggle":
            num = int(command[1])
            if num in S:
                S.remove(num)
            else:
                S.add(num)
        elif oper == "all":
            S = set(range(1, 21))
        elif oper == "empty":
            S.clear()
