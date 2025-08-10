n, m = map(int, input().split())
f1 = f2 = f3 = 2
for i in range(2, n + 1):
    f3 = f1 + f2
    f1 = f2
    f2 = f3
f1 = f2 = 2
for i in range(2, m + 1):
    f3 += f1
    f1, f2 = f2, f1 + f2
print(f3)
