#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = __int128;
#define all(x) x.begin(), x.end()

template <typename F>
int bins(F check, ll ok, ll ng) {
    while (abs(ok - ng) > 1) {
        ll m = (ok + ng) / 2;
        (check(m) ? ok : ng) = m;
    }
    return ok;
}
void solve() {
    int N; cin >> N;
    vector<int> dp(N + 1, 1'000'000'000); dp[0] = 0; dp[1] = 0;
    for (int i = 2; i <= N; ++i) {
        //for (int k = 1; k <= i / 2; ++k) {
        //    dp[i] = min(dp[i], max(2 + dp[k], 1 + dp[i - k]));
        //    //cout << max(2 + dp[k], 1 + dp[i - k]) << ' ';
        //}
        auto check = [&](int m) -> bool {
            return dp[m] + 2 <= dp[i - m] + 1;
            };
        int k = bins(check, 1, i);
        dp[i] = min(dp[i], max(dp[k] + 2, dp[i - k] + 1));
        if (k < i) dp[i] = min(dp[i], max(dp[k + 1] + 2, dp[i - k - 1] + 1));
    }
    //for (auto& x : dp) cout << x << ' ';
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