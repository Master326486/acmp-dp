#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
#define all(x) x.begin(), x.end()

const ll infty = 2'000'000'000'000'000'000LL;
void solve() {
    ll N; cin >> N;
    vector<ll> dp(N + 1); dp[0] = 1;
    for (ll i = 0; i <= N; ++i) if (dp[i] > 0)
        for (ll d = 1; d <= N - i; ++d) {
            dp[i + d] = max(dp[i + d], lcm(dp[i], d));
        }
    cout << dp[N] << endl;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r+", stdin);
    clock_t start_time = clock();
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    //int T; cin >> T;
    //while (T--)
        solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}
