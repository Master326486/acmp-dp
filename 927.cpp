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

const ll MOD = 1'000'000'007;
void solve() {
    string S; cin >> S;
    reverse(all(S));
    ll N = S.size();
    vector<ll> A(N); FOR(i, N) A[i] = S[i] - '0';
    vector<vector<vector<ll>>> dp1(10, vector<vector<ll>>(10, vector<ll>(2, 0))), dp2;
    FOR(i, 10) FOR(j, 10) if ((i + j) % 10 == A[0]) dp1[i][j][i + j > 9] = 1;
    FOR(d, 1, N) {
        dp2.assign(10, vector<vector<ll>>(10, vector<ll>(2, 0)));
        FOR(i, 10) FOR(j, 10) FOR(k, 2) if (dp1[i][j][k] > 0) {
            FOR(a, 10) if (a != i) {
                ll b = A[d] - a - k;
                if (b >= 0 && b != j) {
                    dp2[a][b][0] += dp1[i][j][k];
                    if (dp2[a][b][0] >= MOD) dp2[a][b][0] -= MOD;
                } else if (b < 0 && A[d] + 10 - a - k != j) {
                    b = A[d] + 10 - a - k;
                    dp2[a][b][1] += dp1[i][j][k];
                    if (dp2[a][b][1] >= MOD) dp2[a][b][1] -= MOD;
                }
            }
        }
        swap(dp1, dp2);
    }
    ll ANS = 0;
    FOR(i, 1, 10) FOR(j, 1, 10) ANS = (ANS + dp1[i][j][0]) % MOD;
    cout << ANS << endl;
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