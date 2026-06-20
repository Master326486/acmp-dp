#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
#define all(x) x.begin(), x.end()

const int infty = 1'000'000'000;
void solve() {
    int N, P; cin >> N >> P;
    vector<vector<int>> G(N);
    for (int i = 0, u, v; i < N - 1; ++i) {
        cin >> u >> v; --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<vector<int>> dp(N, vector<int>(P + 1, infty));
    auto dfs = [&](auto& self, int v, int p) -> void {
        dp[v][1] = 0;
        for (auto& u : G[v]) if (u != p) {
            self(self, u, v);
            vector<int> nw(P + 1, infty);
            for (int i = 1; i <= P; ++i) if (dp[v][i] != infty) {
                nw[i] = min(nw[i], dp[v][i] + 1);
                for (int j = 1; i + j <= P; ++j) if (dp[u][j] != infty) {
                    nw[i + j] = min(nw[i + j], dp[v][i] + dp[u][j]);
                }
            }
            dp[v] = nw;
        }
    };
    dfs(dfs, 0, 0);
    int ANS = infty;
    for (int i = 0; i < N; ++i) if (dp[i][P] != infty) {
        ANS = min(ANS, dp[i][P] + (i > 0));
    }
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
