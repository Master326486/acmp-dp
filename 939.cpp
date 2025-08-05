#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = __int128;
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
    int N; cin >> N;
    vector<int> A(N); for (auto& x : A) cin >> x;
    int M = 0; for (auto& x : A) M += x;
    if (M % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
    dp[0][N] = 1;
    vector<bool> tmp;
    FOR(sum, M + 1) if (dp[sum][N]) {
        FOR(i, N) if (!dp[sum][i] && sum + A[i] <= M && !dp[sum + A[i]][N]) {
            tmp = dp[sum]; tmp[i] = 1;
            dp[sum + A[i]] = tmp;
        }
    }
    if (!dp[M / 3][N]) {
        cout << 0 << endl;
        return;
    }
    int K = 0;
    FOR(i, N) if (dp[M / 3][i]) ++K;
    cout << K << endl;
    FOR(i, N) if (dp[M / 3][i]) cout << i + 1 << ' ';
    cout << endl;
}

int main() {
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