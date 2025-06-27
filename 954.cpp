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

const ll MOD = 1'000'000;
void solve() {
    ll N; cin >> N;
    if (N < 10) {
        cout << 0 << endl;
        return;
    }
    if (N == 10) {
        cout << 2 << endl;
        return;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(6, 0)); // [0,1,2] => bottom is facing up
    dp[10][3] = 1; dp[10][0] = 1;                   // [3,4,5] => normal stance
    ll sm;
    FOR(i, 11, N + 1) {
        if (i >= 10) {
            sm = 0;
            FOR(j, 3, 6) sm = (sm + dp[i - 10][j]) % MOD;
            dp[i][0] = (dp[i][0] + sm) % MOD;
            sm = 0;
            FOR(j, 3) sm = (sm + dp[i - 10][j]) % MOD;
            dp[i][3] = (dp[i][3] + sm) % MOD;
        }
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        dp[i][2] = (dp[i][2] + dp[i - 1][1]) % MOD;
        dp[i][4] = (dp[i][4] + dp[i - 1][3]) % MOD;
        dp[i][5] = (dp[i][5] + dp[i - 1][4]) % MOD;
    }
    sm = 0;
    FOR(i, 6) sm = (sm + dp[N][i]) % MOD;
    cout << sm << endl;
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