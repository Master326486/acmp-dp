#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
#define all(x) x.begin(), x.end()

const ll infty = 1e18;
void solve() {
    int N, M; cin >> N >> M;
    vector<pair<ll, int>> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin() + 1, A.end(), greater<>());
    vector<ll> pref(N + 1);
    for (int i = 1; i <= N; ++i)
        pref[i] = pref[i - 1] + A[i].first;
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, infty));
    vector<vector<int>> B(N + 1, vector<int>(M + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= M; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                B[i][j] = 0;
            }
            for (int k = 1; k <= i; ++k) {
                if (dp[k][j - i] != infty) {
                    ll x = dp[k][j - i] + k * (pref[i] - pref[k]);
                    if (x < dp[i][j]) {
                        dp[i][j] = x;
                        B[i][j] = k;
                    }
                }
            }
        }
    }
    vector<int> C(N + 1);
    int ii = N, jj = M;
    while (ii > 0 && jj > 0) {
        int k = B[ii][jj];
        for (int x = 1; x <= ii; ++x) ++C[x];
        jj -= ii;
        ii = k;
    }
    vector<int> ANS(N + 1);
    for (int i = 1; i <= N; ++i)
        ANS[A[i].second] = C[i];
    cout << dp[N][M] << endl;
    for (int i = 1; i <= N; ++i)
        cout << ANS[i] << " \n"[i == N];
}

int main () {
#ifdef LOCAL
    (void)!freopen("input.txt", "r+", stdin);
    clock_t start = clock();
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
#ifdef LOCAL
    cin >> T;
#endif
    while (T --> 0) solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", double(clock() - start) / CLOCKS_PER_SEC * 1000);
#endif

    return 0;
}
