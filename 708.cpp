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
    int N, M; cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M)); FOR(i, N) FOR(j, M) cin >> A[i][j];
    auto rabbit = [&]() -> int {
        int ret = A[0][0], id = 0, mx, x, y;
        FOR(i, 1, M) if (A[0][i] >= ret) { id = i; ret = A[0][i]; }
        A[0][id] = 0;
        FOR(i, 1, N) {
            mx = 0, x = max(id - 1, 0), y = min(id + 2, M);
            FOR(j, x, y) if (A[i][j] >= mx) { mx = A[i][j]; id = j; }
            ret += mx;
            A[i][id] = 0;
        }
        return ret;
        };
    auto hamster = [&]() -> int {
        vector<vector<int>> dp(N, vector<int>(M)), par(N, vector<int>(M)); FOR(i, M) dp[0][i] = A[0][i];
        int x, y;
        FOR(i, 1, N) FOR(j, M) {
            x = max(j - 1, 0LL), y = min(j + 2, ll(M));
            FOR(k, x, y) if (dp[i - 1][k] + A[i][j] >= dp[i][j]) {
                dp[i][j] = dp[i - 1][k] + A[i][j];
                par[i][j] = k;
            }
        }
        int ret = dp[N - 1][0]; x = N - 1, y = 0;
        FOR(i, 1, M) if (dp[x][i] >= ret) { y = i; ret = dp[x][i]; }
        while (x > 0) {
            A[x][y] = 0;
            y = par[x][y];
            --x;
        }
        A[x][y] = 0;
        return ret;
        };
    auto sum = [&]() -> int {
        int ret = 0;
        FOR(i, N) FOR(j, M) ret += A[i][j];
        return ret;
        };
    ll rab = 0, ham = 0, i = 0;
    while (sum() > 0) {
        if (i & 1) ham += hamster();
        else rab += rabbit();
        ++i;
        //for (auto& x : A) {
        //    for (auto& y : x) cout << y << ' ';
        //    cout << endl;
        //}
    }
    cout << rab << ' ' << ham << endl;
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