#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()

#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

const ll infty = ll(1'000'000'000) * 1'000'000'000 * 2;
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M)); FOR(i, N) FOR(j, M) cin >> A[i][j];
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(M, vector<ll>(7, -infty)));
    FOR(i, 1, 7) dp[0][0][i] = A[0][0] * i;
    FOR(i, N) FOR(j, M) if (i != 0 || j != 0) FOR(k, 1, 7) {
        if (i > 0) FOR(x, 1, 7) if (x != 7 - k && x != k)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][x] + A[i][j] * k);
        if (j > 0) FOR(x, 1, 7) if (x != 7 - k && x != k)
            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][x] + A[i][j] * k);
    }
    ll ans = -infty;
    FOR(i, 1, 7) ans = max(ans, dp[N - 1][M - 1][i]);
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

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}