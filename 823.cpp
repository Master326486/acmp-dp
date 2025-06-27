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
    ll n; cin >> n;
    ll mxy = 0;
    vector<pair<ll, ll>> a(n); for (auto& x : a) {
        cin >> x.first >> x.second;
        mxy = max(mxy, x.second);
    }
    vector<ll> l(mxy + 1, infty), r(mxy + 1, -1);
    for (auto& x : a) {
        l[x.second] = min(l[x.second], x.first);
        r[x.second] = max(r[x.second], x.first);
    }
    vector<vector<ll>> dp(mxy + 1, vector<ll>(2, infty)); // 0 = l   1 = r
    if (l[1] == infty) {
        l[1] = 1;
        r[1] = 1;
        dp[1][0] = 0;
        dp[1][1] = 0;
    }
    else {
        dp[1][0] = r[1] - 1 + r[1] - l[1];
        dp[1][1] = r[1] - 1;
    }
    FOR(i, 2, mxy + 1) {
        if (l[i] == infty) {
            l[i] = l[i - 1];
            r[i] = r[i - 1];
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
            continue;
        }
        dp[i][0] = min(
            dp[i - 1][0] + 1 + abs(l[i - 1] - r[i]) + r[i] - l[i],
            dp[i - 1][1] + 1 + abs(r[i - 1] - r[i]) + r[i] - l[i]
        );
        dp[i][1] = min(
            dp[i - 1][0] + 1 + abs(l[i - 1] - l[i]) + r[i] - l[i],
            dp[i - 1][1] + 1 + abs(r[i - 1] - l[i]) + r[i] - l[i]
        );
    }
    //for (auto& x : dp) cout << x[0] << ' ' << x[1] << endl;
    cout << min(dp[mxy][0], dp[mxy][1]) << endl;
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