#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
 
const ll infty = 2'000'000'000'000'000'000LL;
void solve() {
    string S; cin >> S;
    int N = S.size();
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        dp[i][i] = 1;
        if (i < N - 1) {
            dp[i][i + 1] = 2 + (S[i] == S[i + 1]);
        }
    }
    for (int len = 3; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            if (S[i] != S[j]) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }
        }
    }
    cout << dp[0][N - 1] << endl;
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