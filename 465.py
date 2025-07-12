n = int(input())
dp1 = [0] * 2
dp1[0] = 1
dp1[1] = 1
for _ in range(n - 1):
    dp2 = [0] * 2
    dp2[0] = dp1[0] + dp1[1]
    dp2[1] = dp1[0]
    dp1 = dp2
print(sum(dp1))
