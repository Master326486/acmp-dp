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
#define MAX(x) (*max_element(all(x)))

void solve() {
    ll N, M; cin >> N >> M;
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, -1));
    dp[1][1] = 0;
    FOR(i, 1, N + 1) FOR(j, 1, M + 1) {
        if (dp[i][j] == -1) dp[i][j] = 0;
        if (dp[i][j] == 0) {
            FOR(k, j + 1, M + 1) if (dp[i][k] == -1) dp[i][k] = 1 - dp[i][j];
            FOR(k, i + 1, N + 1) if (dp[k][j] == -1) dp[k][j] = 1 - dp[i][j];
            // i + k <= N => k <= N - i
            FOR(k, 1, min(N + 1 - i, M + 1 - j)) if (dp[i + k][j + k] == -1) dp[i + k][j + k] = 1 - dp[i][j];
        }
    }
    //for (auto& x : dp) {
    //    for (auto& y : x) cout << y << ' ';
    //    cout << endl;
    //}
    cout << 2 - dp[N][M] << endl;
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