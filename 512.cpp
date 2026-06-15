#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<string> A(N); for (auto& x : A) cin >> x;
    if (K > min(N, M)) {
        cout << "0\n";
        return;
    }
    int X = 1 << M;
    vector<vector<ll>> dp(N + 1, vector<ll>(X)), dp1;
    dp[0][0] = 1;
    ll ANS = 0;
    for (int i = 0; i < N; ++i) {
        dp1.assign(N + 1, vector<ll>(1LL << M, 0));
        for (int j = 0; j < N; ++j) {
            for (int mask = 0; mask < X; ++mask) {
                dp1[j][mask] += dp[j][mask];
                for (int k = 0; k < M; ++k) {
                    if (!((mask >> k) & 1) && A[i][k] == 'Y') {
                        dp1[j + 1][mask ^ (1 << k)] += dp[j][mask];
                    }
                }
            }
        }
        swap(dp, dp1);
    }
    for (int mask = 0; mask < X; ++mask)
        ANS += dp[K][mask];
    cout << ANS << endl;
}

int main () {
#ifdef LOCAL
    (void)!freopen("input.txt", "r+", stdin);
    clock_t start = clock();
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
#ifdef LOCAL
    cin >> T;
#endif
    while (T --> 0) solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", double(clock() - start) / CLOCKS_PER_SEC * 1000);
#endif

    return 0;
}
