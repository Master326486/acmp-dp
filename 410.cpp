#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()

const int infty = 1'000'000'000;
void solve() {
    int N, M; cin >> N >> M;
    int MAX = M + 5;
    vector<vector<int>> dp(MAX, vector<int>(M, infty));
    vector<vector<pair<int, int>>> par(MAX, vector<pair<int, int>>(M, make_pair(-1, -1)));
    int R = (M - N % M) % M;
    dp[0][0] = 0;
    for (int i = 0; i < MAX - 1; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int d = 0; d < 10; ++d) {
                int nw = dp[i][j] + d;
                if (nw < dp[i + 1][(j * 10 + d) % M]) {
                    dp[i + 1][(j * 10 + d) % M] = nw;
                    par[i + 1][(j * 10 + d) % M] = { i, j };
                }
            }
        }
    }
    int i = 0;
    for (int j = 0; j < MAX; ++j) {
        if (dp[j][R] < dp[i][R]) i = j;
    }
    int j = R;
    string ANS;
    while (i > 0) {
        auto [ni, nj] = par[i][j];
        if (i != -1) ANS += '0' + dp[i][j] - dp[ni][nj];
        i = ni, j = nj;
    }
    if (ANS.empty()) ANS = "0";
    reverse(all(ANS));
    cout << ANS << endl;
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
