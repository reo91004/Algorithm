A = [1, 3, 5, 2, 4]
B = [5, 3, 1, 4, 2]

sorted_pairs = sorted(zip(A, B), key=lambda x: x[1], reverse=True)
A = [pair[0] for pair in sorted_pairs]

print(A)  # 출력: [1, 2, 3, 4, 5]
