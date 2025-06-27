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

using ld = long double;
void solve() {
    ll N; cin >> N;
    // 0 = 5, 1 = 9
    if (N <= 2) {
        if (N == 1) cout << 2 << endl;
        else cout << 4 << endl;
        return;
    }
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(2)));
    FOR(i, 2) FOR(j, 2) dp[2][i][j] = 1;
    FOR(i, 3, N + 1) {
        dp[i][0][0] = dp[i - 1][1][0];
        dp[i][0][1] = dp[i - 1][0][0] + dp[i - 1][1][0];
        dp[i][1][0] = dp[i - 1][1][1] + dp[i - 1][0][1];
        dp[i][1][1] = dp[i - 1][0][1];
    }
    ll ANS = 0;
    FOR(i, 2) FOR(j, 2) ANS += dp[N][i][j];
    cout << ANS << endl;
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