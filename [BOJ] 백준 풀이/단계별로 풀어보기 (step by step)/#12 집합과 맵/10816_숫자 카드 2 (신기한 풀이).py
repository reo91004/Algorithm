from sys import stdin
_ = stdin.readline()
N = sorted(map(int,stdin.readline().split()))
_ = stdin.readline()
M = list(map(int,stdin.readline().split()))
index, m_dic = 0, {}

for m in sorted(M):
    cnt = 0
    if m not in m_dic:
        while index < len(N):
            if m == N[index]:
                cnt += 1; index += 1
            elif m > N[index]:
                index += 1
            else: break
        m_dic[m] = cnt

print(' '.join(str(m_dic[m]) for m in M))