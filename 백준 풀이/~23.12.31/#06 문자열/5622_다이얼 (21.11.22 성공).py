alp = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
text = input()
res = 0

for j in range(len(text)):
    for i in alp:
        if text[j] in i:
            res += alp.index(i)+3

print(res)
