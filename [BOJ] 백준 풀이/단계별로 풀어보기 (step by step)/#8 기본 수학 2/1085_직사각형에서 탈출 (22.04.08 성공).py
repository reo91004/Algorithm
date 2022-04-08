x, y, w, h = map(int, input().split())
res1 = min(x, y);
res2 = min(w - x, h - y);

print(min(res1, res2))