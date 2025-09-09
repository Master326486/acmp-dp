/*
Wrong answer
Test 10
Time 0.03
Memory 488 KB

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
#define all(x) x.begin(), x.end()

void solve() {
    int N, M; cin >> N >> M;
    vector<string> A(N); for (auto& x : A) cin >> x;
    if (M > N) {
        vector<string> B(M, string(N, '.'));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                B[j][i] = A[i][j];
        swap(N, M);
        A = B;
    }
    vector<vector<vector<i128>>> dp(N + 1, vector<vector<i128>>(M + 1, vector<i128>(1 << M)));
    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j <= M; ++j)
            for (int msk = 0; msk < (1 << M); ++msk)
                if (dp[i][j][msk] > 0) {
                    i128 x = dp[i][j][msk];
                    if (j == M) {
                        dp[i + 1][0][msk] += x;
                        continue;
                    }
                    if (A[i][j] == '#') {
                        if ((msk >> j) & 1) continue;
                        dp[i][j + 1][msk] += x;
                        continue;
                    }
                    if ((msk >> j) & 1) {
                        dp[i][j + 1][msk & ~(1 << j)] += x;
                        continue;
                    }
                    dp[i][j + 1][msk] += x;
                    for (int sz = 2; i + sz <= N && j + sz <= M; ++sz) {
                        bool ok = 1;
                        for (int k = 0; k < sz && ok; ++k)
                            for (int m = 0; m < sz; ++m) {
                                if (A[i + k][j + m] == '#') { ok = 0; break; }
                                if (k == 0 && ((msk >> (j + m)) & 1)) { ok = 0; break; }
                            }
                        if (!ok) break;
                        int nw = msk;
                        for (int k = 1; k < sz; ++k)
                            for (int m = 0; m < sz; ++m)
                                nw |= (1 << (j + m));
                        dp[i][j + sz][nw] += x;
                    }
                }
    string ans;
    i128 X = dp[N][0][0];
    if (X == 0) {
        cout << 0 << endl;
        return;
    }
    while (X > 0) {
        ans += '0' + X % 10;
        X /= 10;
    }
    reverse(all(ans));
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r+", stdin);
    clock_t start_time = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}