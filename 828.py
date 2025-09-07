N, K = map(int, input().split())
dp = [0] * (K + 1)
dp[1] = 1
for i in range(2, N + 1):
    dp2 = [0] * (K + 1)
    for j in range(1, K + 1):
        dp2[j] = dp[j] * j + dp[j - 1]
    dp = dp2
print(sum(dp))