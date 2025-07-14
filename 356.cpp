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
    int E, F, N, M; cin >> E >> F >> M; N = F - E;
    vector<int> P(M), W(M); FOR(i, M) cin >> P[i] >> W[i];
    vector<ll> dp(N + 1, infty); dp[0] = 0;
    FOR(i, 1, N + 1) FOR(j, M) if (i >= W[j] && dp[i - W[j]] != infty) dp[i] = min(dp[i], dp[i - W[j]] + P[j]);
    if (dp[N] == infty) { cout << "This is impossible." << endl; return; }
    cout << dp[N] << ' ';
    dp.assign(N + 1, -1); dp[0] = 0;
    FOR(i, 1, N + 1) FOR(j, M) if (i >= W[j] && dp[i - W[j]] != -1) dp[i] = max(dp[i], dp[i - W[j]] + P[j]);
    cout << dp[N] << endl;
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