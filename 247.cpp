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
    vector<ll> A(N); for (auto& x : A) cin >> x;
    vector<vector<pair<ll, ll>>> dp(N + 1, vector<pair<ll, ll>>(N + 2, make_pair(infty, 0LL)));
    dp[0][0].first = 0;
    FOR(i, 1, N + 1) {
        FOR(j, N + 1) {
            if (dp[i - 1][j].first + A[i - 1] < dp[i][j + (A[i - 1] > 100)].first)
                dp[i][j + (A[i - 1] > 100)] = make_pair(dp[i - 1][j].first + A[i - 1], dp[i - 1][j].second);
            if (j > 0 && dp[i - 1][j].first < dp[i][j - 1].first) {
                dp[i][j - 1] = dp[i - 1][j];
                ++dp[i][j - 1].second;
            }
        }
    }
   // for (auto& x : dp) {
     //   for (auto& y : x) cout << y.first << ' ';
       // cout << endl;
    //}
    ll ANS = infty; pair<ll, ll> coans;
    FOR(j, N + 2) if (dp[N][j].first <= ANS) {
        ANS = dp[N][j].first;
        coans = make_pair(j, dp[N][j].second);
    }
    cout << ANS << endl << coans.first << ' ' << coans.second << endl;
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