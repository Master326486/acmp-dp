#include <bits/stdc++.h>
#define LOCAL
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
    ll N, C, K; cin >> N >> C >> K;
    ll MOD = 10; FOR(K - 1) MOD *= 10;
    string S; cin >> S;
    vector<ll> dp(N + 1);
    auto add = [&](ll i, ll x) -> void {
        dp[i] += x;
        if (dp[i] >= MOD) dp[i] -= MOD;
        };
    dp[0] = 1;
    FOR(i, 1, N + 1) {
        ll x = S[i - 1] - '0';
        ll j = i - 1;
        ll mul = 10;
        while (mul <= C * 10 && x <= C && j >= 0) {
            if (S[j] != '0' || j == i - 1) add(i, dp[j]);
            --j;
            x += (S[j] - '0') * mul;
            mul *= 10;
        }
    }
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
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}