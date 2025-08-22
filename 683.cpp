#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = __int128;
#define all(x) x.begin(), x.end()

const ll infty = 2'000'000'000'000'000'000LL;
void solve() {
    ll N; cin >> N;
    vector<ll> A(N); for (auto& x : A) cin >> x;
    if (N <= 2) {
        cout << 0 << endl;
        return;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, infty));
    for (int i = 0; i < N - 1; ++i) {
        dp[i][i] = 0;
        dp[i][i + 1] = 0;
    }
    for (int sz = 2; sz < N; ++sz)
        for (int i = 0, j; i + sz < N; ++i) {
            j = i + sz;
            for (int k = i + 1; k < j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[k] * (A[i] + A[j]));
        }
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