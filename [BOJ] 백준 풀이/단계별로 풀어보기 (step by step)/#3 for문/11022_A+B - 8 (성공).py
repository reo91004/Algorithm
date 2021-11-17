val = int(input())

for i in range(val):
    x, y = map(int, input().split())
    print(f"Case #{i+1}: {x} + {y} = {x + y}")