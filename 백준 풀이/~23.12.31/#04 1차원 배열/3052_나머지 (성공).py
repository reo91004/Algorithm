arr = []

for i in range(10):
    n = int(input())
    arr.append(n % 42)
    
arr = set(arr)  # 중복이 제거된다.
print(len(arr))
