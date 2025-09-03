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
    int N, M; cin >> N >> M;
    if (N > M) swap(N, M);
    if (N == 1) {
        cout << (1 << M) << endl;
        return;
    }
    int K = (1 << N);
    vector<vector<bool>> good(K, vector<bool>(K, 1));
    for (int mask = 0; mask < K; ++mask)
        for (int mask2 = 0; mask2 < K; ++mask2)
            for (int bit = 0; bit < N - 1; ++bit)
                if (((mask >> bit) & 1) == ((mask >> (bit + 1)) & 1) &&
                    ((mask >> bit) & 1) == ((mask2 >> bit) & 1) &&
                    ((mask >> bit) & 1) == ((mask2 >> (bit + 1)) & 1)) {
                    good[mask][mask2] = 0;
                    good[mask2][mask] = 0;
                    break;
                }
    vector<ll> dp(K), dp2;
    for (int mask = 0; mask < K; ++mask)
        dp[mask] = 1;
    for (int i = 2; i <= M; ++i) {
        dp2.assign(K, 0);
        for (int mask = 0; mask < K; ++mask)
            for (int mask2 = 0; mask2 < K; ++mask2)
                if (good[mask][mask2])
                    dp2[mask2] += dp[mask];
        swap(dp, dp2);
    }
    ll ANS = 0;
    for (int mask = 0; mask < K; ++mask) ANS += dp[mask];
    cout << ANS << endl;
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
