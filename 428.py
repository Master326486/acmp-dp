MAX = 85
N = int(input())
S = input()
btns = ["", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]
B = {}
I = {}
for btn, keys in enumerate(btns):
    for i, c in enumerate(keys):
        B[c] = btn
        I[c] = i + 1
A = []
for c in S:
    b = B[c]
    i = I[c]
    mx = 4 if b in (7, 9) else 3
    bs = []
    if A and A[-1][0] == b:
        A[-1][1] += i
    else:
        A.append([b, i, mx])
c3 = [[0] * MAX for _ in range(MAX * 4)]
c4 = [[0] * MAX for _ in range(MAX * 4)]
c3[0][0] = 1
c4[0][0] = 1
for c in range(1, 321):
    for k in range(1, 81):
        for x in range(1, 4):
            if c >= x:
                c3[c][k] += c3[c - x][k - 1]
        for x in range(1, 5):
            if c >= x:
                c4[c][k] += c4[c - x][k - 1]
M = len(A)
dp = [[0] * (N + 1) for _ in range(M + 1)]
dp[0][0] = 1
for i in range(1, M + 1):
    b, cnt, mx = A[i - 1]
    c = c4 if mx == 4 else c3
    for j in range(1, N + 1):
        for k in range(1, min(j, cnt) + 1):
            cc = c[cnt][k]
            if cc > 0:
                dp[i][j] += dp[i - 1][j - k] * cc
print(dp[M][N])
