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

const ll infty = ll(1'000'000'000) * 1'000'000'000 * 2;
void solve() {
    ll N; cin >> N;
    vector<ll> A(N); for (auto& x : A) cin >> x;
    sort(all(A));
    vector<ll> dp1(N); // last not taken
    vector<pair<ll, ll>> dp2(N); // last taken .fi = max v, .se = cur v
    dp2[0] = make_pair(infty, infty);
    FOR(i, 1, N) {
        dp1[i] = dp2[i - 1].first;
        dp2[i] = make_pair(max(dp1[i - 1], A[i] - A[i - 1]), A[i] - A[i - 1]);
        ll cand = max(dp2[i - 1].first, dp2[i - 1].second + A[i] - A[i - 1]);
        if (i > 1 && cand < dp2[i].first) dp2[i] = make_pair(cand, dp2[i - 1].second + A[i] - A[i - 1]);
    }
    cout << dp2[N - 1].first << endl;
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