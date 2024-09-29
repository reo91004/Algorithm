N = int(input())
cnt = 1
layer = 1

while N > cnt :
    cnt += 6 * layer 
    layer += 1

print(layer)