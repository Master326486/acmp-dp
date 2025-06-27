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

void solve() {
    ll N; cin >> N;
    vector<string> As(N); for (auto& x : As) cin >> x;
    vector<vector<ll>> A(N, vector<ll>(N, 0));
    FOR(i, N) FOR(j, N) A[i][j] = As[i][j] - '0';
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 1'000'000'000)); dp[0][1] = 0;
    vector<vector<pair<ll, ll>>> par(N + 1, vector<pair<ll, ll>>(N + 1));
    FOR(i, 1, N + 1) FOR(j, 1, N + 1) {
        if (dp[i - 1][j] < dp[i][j - 1]) {
            par[i][j] = make_pair(i - 1, j);
            dp[i][j] = dp[i - 1][j] + A[i - 1][j - 1];
        } else {
            par[i][j] = make_pair(i, j - 1);
            dp[i][j] = dp[i][j - 1] + A[i - 1][j - 1];
        }
    }
    vector<string> ANS(N, string(N, '.')); ANS[0][0] = '#';
    ll i = N, j = N;
    pair<ll, ll> p;
    while (i != 1 || j != 1) {
        ANS[i - 1][j - 1] = '#';
        p = par[i][j];
        i = p.first;
        j = p.second;
    }
    for (auto& x : ANS) cout << x << endl;
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