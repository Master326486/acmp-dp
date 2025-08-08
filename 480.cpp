#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = __int128;
#define all(x) x.begin(), x.end()

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (auto& x : A) cin >> x;
    int K; cin >> K;
    vector<int> suff(N + 1); suff[N] = A[N - 1];
    for (int i = N - 1; i >= 1; --i) suff[i] = suff[i + 1] + A[i - 1];
    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1));
    for (int i = 1; i <= K; ++i) dp[N][i] = A[N - 1];
    for (int i = N - 1; i >= 1; --i) for (int j = 1; j <= K; ++j) {
        if (i + j > N) dp[i][j] = suff[i];
        else {
            dp[i][j] = max({
                dp[i][j],
                dp[i][j - 1],
                suff[i] - dp[i + j][j]
                });
        }
    }
    cout << dp[1][K] << endl;
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