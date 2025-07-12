N = int(input())
a = 1
b = 1
for i in range(1, N):
    c = a + b
    a = b
    b = c
print(b * b)
