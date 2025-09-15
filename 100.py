N = int(input())
M = N // 2
dp = [[0] * (9 * M + 1) for _ in range(M + 1)]
dp[0][0] = 1
for i in range(M):
    for s in range(9 * i + 1):
        if dp[i][s] > 0:
            for d in range(10):
                if s + d <= 9 * M + 1:
                    dp[i + 1][s + d] += dp[i][s]
ANS = 0
for s in range(9 * M + 1):
    ANS += dp[M][s] * dp[M][s]
print(ANS)
