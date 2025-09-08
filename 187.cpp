#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
#define all(x) x.begin(), x.end()

void solve() {
    ll N; cin >> N;
    vector<vector<ll>> dp(2 * N, vector<ll>(2 * N));
    dp[1][1] = 1;
    for (int i = 1; i < 2 * N; ++i)
        for (int j = 1; j < 2 * N; ++j)
            if (j - i <= N - 1 && dp[i][j] > 0) {
                if (j + 1 - i <= N - 1) dp[i][j + 1] += dp[i][j];
                if (i < N) {
                    if (j - i - 1 <= N - 1) dp[i + 1][j] += dp[i][j];
                    dp[i + 1][j + 1] += dp[i][j];
                } else {
                    if (i < 2 * N - 1 && j > 1) dp[i + 1][j - 1] += dp[i][j];
                    if (i < 2 * N - 1 && j - i - 1 <= N - 1) dp[i + 1][j] += dp[i][j];
                }
            }
    //for (auto& x : dp) {
    //    for (auto& y : x) cout << y << ' ';
    //    cout << endl;
    //}
    cout << dp[2 * N - 1][N] << endl;
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