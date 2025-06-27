/*
Wrong answer
Test 5
Time 0.03
Memory 456 KB

*/

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

const ll infty = 1'000'000'000;
void solve() {
    ll N; cin >> N;
    vector<ll> M(N), K(N); FOR(i, N) cin >> M[i] >> K[i];
    vector<vector<ll>> dp(N, vector<ll>(N, infty));
    FOR(i, N) dp[i][i] = 0;
    FOR(len, 2, N + 1) {
        FOR(i, N - len + 1) {
            ll j = i + len - 1;
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + M[i] * K[j]);
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + M[i] * K[j]);
        }
    }
    //for (auto& x : dp) {
    //    for (auto& y : x) cout << y << ' ';
    //    cout << endl;
    //}
    cout << dp[0][N - 1] << endl;
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