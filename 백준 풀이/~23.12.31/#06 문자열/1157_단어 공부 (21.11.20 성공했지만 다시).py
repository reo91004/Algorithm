# C++식으로 똑같이 짜기보다는, 파이썬의 사기성을 이용해보자.

text = input().upper()

# 중복된 단어 없앰
rm_overlap = list(set(text))
# 중복 셀 리스트
overlap = []

# 중복을 없앤 리스트를 기준으로 원래 문자열의 개수를 overlap에 저장 
# ex) zZa -> Z, a 순서대로, Z Z A 이므로 2, 1이 들어감
for i in rm_overlap:
    overlap.append(text.count(i))

# max 값을 가진 요소가 2개 이상 있으면 중복이므로 ? 출력
if overlap.count(max(overlap)) > 1:
    print("?")
else: # 아니라면 overlap의 max요소의 인덱스를 뽑아 중복된 단어 없앤 리스트의 단어 출력
    # ex) ZZA, Z/A, 2/1, 2의 인덱스는 0, Z의 인덱스도 0임.
    print(rm_overlap[overlap.index(max(overlap))])
