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

using ld = long double;
void solve() {
    ll N, Q; cin >> N >> Q;
    if (Q < N || Q > 6 * N) {
        cout << 0 << endl;
        return;
    }
    vector<ld> dp1(Q + 1), dp2; dp1[0] = 1;
    ld os = ld(1) / ld(6);
    FOR(i, 1, N + 1) {
        dp2.assign(Q + 1, 0);
        FOR(j, 1, Q + 1) {
            dp2[j] += dp1[j - 1] * os;
            if (j > 1) dp2[j] += dp1[j - 2] * os;
            if (j > 2) dp2[j] += dp1[j - 3] * os;
            if (j > 3) dp2[j] += dp1[j - 4] * os;
            if (j > 4) dp2[j] += dp1[j - 5] * os;
            if (j > 5) dp2[j] += dp1[j - 6] * os;
        }
        swap(dp1, dp2);
    }
    cout << dp1[Q] << endl;
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