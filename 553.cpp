#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
#define all(x) x.begin(), x.end()

const ll infty = 2'000'000'000'000'000'000LL;
void solve() {
    int N; cin >> N;
    vector<ll> M(N), K(N);
    for (int i = 0; i < N; ++i)
        cin >> M[i] >> K[i];
    vector<vector<ll>> dp(N, vector<ll>(N, infty));
    for (int i = 0; i < N; ++i) dp[i][i] = 0;
    for (int sz = 2; sz <= N; ++sz) {
        for (int i = 0, j; i <= N - sz; ++i) {
            j = i + sz - 1;
            for (int k = i; k < j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + M[i] * K[j]);
        }
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
    //int t; cin >> t;
    //while(t--)
        solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}