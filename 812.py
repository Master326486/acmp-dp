N, A = map(int, input().split())
dp = 0
pref = [0] * (N + 1)
pref[0] = 1
j = 0
x = 0
for i in range(1, N + 1):
    j = i - A - 1
    x = 0
    if j >= 0:
        x = pref[j]
    dp = pref[i - 1] - x
    pref[i] = pref[i - 1] + dp
print(dp)
