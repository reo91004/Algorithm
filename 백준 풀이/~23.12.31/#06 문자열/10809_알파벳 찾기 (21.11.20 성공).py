val = input()
alp = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -
       1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1]

for i in range(len(val)):
    if alp[ord(val[i]) - 97] != -1:
        continue
    alp[ord(val[i]) - 97] = i

for i in range(26):
    print(f"{alp[i]} ", end='')
