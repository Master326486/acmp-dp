#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()

const ll infty = 2'000'000'000'000'000'000LL;
void solve() {
    ll N, w, L, r, R; cin >> N >> w >> L >> r >> R;
    if (w * N > L) { cout << "No solution.\n"; return; }
    vector<ll> A(L + 1); for (int i = 1; i <= L; ++i) cin >> A[i];
    vector<ll> cost(L - w + 2); cost[0] = infty;
    for (int i = 1; i <= w; ++i) cost[1] += A[i];
    for (int i = w + 1; i <= L; ++i) cost[i - w + 1] = cost[i - w] + A[i] - A[i - w];
    vector<ll> dp(L - w + 2, infty), dp2;
    for (int i = max(r + 1, 1LL); i <= min(R + 1, L - w + 1); ++i) dp[i] = cost[i];
    for (int i = 2; i <= N; ++i) {
        dp2.assign(L - w + 2, infty);
        deque<ll> q;
        for (int j = 1; j <= L - w + 1; ++j) {
            int k = j - r - w;
            if (k >= 1) {
                while (!q.empty() && dp[q.back()] > dp[k]) q.pop_back();
                q.emplace_back(k);
            }
            //for (auto& x : q) cout << x << ' ';
            //cout << endl;
            if (q.front() < j - R - w) q.pop_front();
            if (!q.empty()) dp2[j] = dp[q.front()] + cost[j];
        }
        swap(dp, dp2);
    }
    ll ANS = infty;
    //cout << L - R - w << ' ' << L - r - w << endl;
    for (int i = max(L + 1 - R - w, 1LL); i <= min(L + 1 - r - w, L - w + 1); ++i)
        ANS = min(ANS, dp[i]);
    if (ANS == infty) {
        cout << "No solution.\n";
        return;
    }
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