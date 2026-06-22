import sys

N = int(input())
if N == 1:
    print(1)
    sys.exit()
G = [[] for _ in range(N + 1)]
for i in range(N - 1):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
dp = [[0, 0, 0] for _ in range(N + 1)]

def dfs(v, p):
    ch = []
    for u in G[v]:
        if u != p:
            dfs(u, v)
            ch.append(u)
    M = len(ch)
    if M == 0:
        dp[v][0] = 1
        dp[v][1] = 1
        return
    pref = [1] * (M + 1)
    for i in range(M):
        pref[i + 1] = pref[i] * dp[ch[i]][0]
    suff = [1] * (M + 1)
    for i in range(M - 1, -1, -1):
        suff[i] = suff[i + 1] * dp[ch[i]][0]
    x, y, z = 0, 0, 0
    for i in range(M):
        u = ch[i]
        p = pref[i] * suff[i + 1]
        x += dp[u][2] * p
        y += (dp[u][1] + dp[u][2]) * p
    cur = 0
    for i in range(M):
        u = ch[i]
        su = dp[u][1] + dp[u][2]
        z += su * suff[i + 1] * cur
        cur = cur * dp[u][0] + su * pref[i]
    dp[v][0] = pref[M] + x + z
    dp[v][1] = pref[M]
    dp[v][2] = y

dfs(1, 0)
print(dp[1][0])

