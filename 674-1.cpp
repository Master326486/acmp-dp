#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
 
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
 
bool multicase = 0;
void solve() {
    ll N; cin >> N;
    map<ll, ll> dp;
    dp[N] = 1;
    while (N > 3) {
        dp[N / 2] += dp[N];
        dp[(N + 1) / 2] += dp[N];
        dp.erase(N);
        N = dp.rbegin()->first;
    }
    cout << dp[3] << '\n';
}
 
signed main()
{
 //   freopen("input.txt", "r+", stdin);
    int T = 1;
    if (multicase) cin >> T;
    FOR(T) solve();
 
    return 0;
}