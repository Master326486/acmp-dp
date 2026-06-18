#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
#define all(x) x.begin(), x.end()

const int infty = 1'000'000'000;
void solve() {
    int N; cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];
    vector<vector<u32>> suff(N);
    for (int i = 0; i < N; ++i) {
        suff[i].assign(R[i] + 2, 0);
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < N; ++i) {
        if (L[i] < 0) {
            int p = -L[i] - 1;
            G[p].emplace_back(i);
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int v = R[i]; v >= 0; --v) {
            u32 x = 1;
            for (auto& u : G[i]) {
                if (v <= R[u]) {
                    x *= suff[u][v];
                } else {
                    x = 0;
                    break;
                }
            }
            suff[i][v] = suff[i][v + 1] + x;
        }
    }
    u32 ANS = 1;
    for (int i = 0; i < N; ++i) {
        if (L[i] >= 0) {
            if (L[i] > R[i]) ANS = 0;
            else ANS *= suff[i][L[i]];
        }
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
