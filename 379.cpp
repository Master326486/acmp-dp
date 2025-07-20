#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()

#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

void solve() {
    int D, M; cin >> D >> M; --D, --M;
    vector<int> cnt = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<vector<bool>> dp(12, vector<bool>(31)); dp[11][30] = 1;
    FOR_R(m, 12) FOR_R(d, 31) if (d < cnt[m]) {
        int nd = d + 1, nm = m;
        if (nd < cnt[nm] && !dp[nm][nd]) dp[m][d] = 1;
        ++nd;
        if (nd < cnt[nm] && !dp[nm][nd]) dp[m][d] = 1;
        nd -= 2; ++nm;
        if (nd < cnt[nm] && nm < 12 && !dp[nm][nd]) dp[m][d] = 1;
        ++nm;
        if (nd < cnt[nm] && nm < 12 && !dp[nm][nd]) dp[m][d] = 1;
    }
    cout << 1 + !dp[M][D] << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r+", stdin);
    clock_t start_time = clock();
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}