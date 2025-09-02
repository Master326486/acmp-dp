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
    string A, B; cin >> A >> B;
    if (A.find('?') != string::npos || A.find('*') != string::npos) {
        swap(A, B);
    } else if (B.find('?') == string::npos && B.find('*') == string::npos) {
        cout << (A == B ? "YES" : "NO") << endl;
        return;
    }
    int N = A.size(), M = B.size();
    vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= M && B[i - 1] == '*'; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j) {
            if (B[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (B[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] && B[i - 1] == A[j - 1];
        }
    cout << (dp[M][N] ? "YES" : "NO") << endl;
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
