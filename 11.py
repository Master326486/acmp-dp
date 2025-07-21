K, N = map(int, input().split())
dp = [0] * (N + 1)
dp[0] = 1
for i in range(1, N + 1):
    for j in range(max(0, i - K), i):
        dp[i] += dp[j]
print(dp[N])