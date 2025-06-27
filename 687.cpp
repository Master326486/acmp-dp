#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = __int128;
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
    ll N, M; cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M)); for (auto& x : A) for (auto& y : x) cin >> y;
    vector<vector<ll>> dp(N, vector<ll>(M)), par(N, vector<ll>(M, -1));
    FOR(i, N) dp[i][0] = A[i][0];
    FOR(j, 1, M) FOR(i, N) {
        ll res = infty;
        if (i > 0 && dp[i - 1][j - 1] < res) {
            res = dp[i - 1][j - 1];
            par[i][j] = i - 1;
        }
        if (dp[i][j - 1] < res) {
            res = dp[i][j - 1];
            par[i][j] = i;
        }
        if (i < N - 1 && dp[i + 1][j - 1] < res) {
            res = dp[i + 1][j - 1];
            par[i][j] = i + 1;
        }
        dp[i][j] = res + A[i][j];
    }
    //for (auto& x : dp) {
    //    for (auto& y : x) cout << y << ' ';
    //    cout << endl;
    //}
    ll x = 0;
    FOR(i, 1, N) if (dp[i][M - 1] < dp[x][M - 1]) x = i;
    ll i = x, j = M - 1;
    vector<int> ANS; ANS.push_back(x + 1);
    while (j > 0) {
        i = par[i][j];
        --j;
        ANS.push_back(i + 1);
    }
    reverse(all(ANS));
    FOR(i, M) cout << ANS[i] << " \n"[i == M - 1];
    cout << dp[x][M - 1] << endl;
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