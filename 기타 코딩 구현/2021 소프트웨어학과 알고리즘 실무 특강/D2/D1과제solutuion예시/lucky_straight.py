import sys
input = sys.stdin.readline

n = input().rstrip()
left = n[:len(n)//2]
right = n[len(n)//2:]

left_arr = list(map(int,left))
right_arr = list(map(int,right))

if sum(left_arr) == sum(right_arr) :
    print("LUCKY")
else :
    print("READY")