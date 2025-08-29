#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()

#define int ll
const int infty = 1'000'000'000'000'000'000LL;
void solve() {
    int N, L; cin >> N >> L;
    vector<int> P(N), R(N), Q(N), F(N);
    for (int i = 0; i < N; ++i) cin >> P[i] >> R[i] >> Q[i] >> F[i];
    int sum = 0;
    for (auto& x : F) sum += x;
    if (L == 0) {
        cout << 0 << endl;
        return;
    }
    if (sum < L) {
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> dp(sum + 1, vector<int>(N + 1, infty));
    for (int i = 0; i <= N; ++i) dp[0][i] = 0;
    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            for (int take = 0; take <= min(i, F[j - 1]); ++take) {
                dp[i][j] = min(dp[i][j], dp[i - take][j - 1] + take * (take >= R[j - 1] ? Q[j - 1] : P[j - 1]));
            }
        }
    }
    //for (auto& x : dp) {
    //    for (auto& y : x)
    //        cout << y << ' ';
    //    cout << endl;
    //}
    int ANS = infty;
    for (int i = L; i <= sum; ++i) ANS = min(ANS, dp[i][N]);
    cout << ANS << endl;
}

signed main() {
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