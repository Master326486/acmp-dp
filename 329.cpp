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
    ll N; cin >> N;
    vector<ll> A(N); for (auto& x : A) cin >> x;
    vector<ll> dp(N);
    dp[0] = A[0];
    dp[1] = A[1] + max(A[0], 0LL);
    vector<ll> par(N);
    par[0] = -1;
    par[1] = (A[0] > 0 ? 0 : -1);
    FOR(i, 2, N) {
        if (dp[i - 1] > dp[i - 2]) {
            dp[i] = dp[i - 1];
            par[i] = i - 1;
        } else {
            dp[i] = dp[i - 2];
            par[i] = i - 2;
        }
        dp[i] += A[i];
    }
    cout << dp[N - 1] << endl;
    ll i = N - 1;
    vector<ll> ANS;
    while (i != -1) {
        ANS.emplace_back(i);
        i = par[i];
    }
    reverse(all(ANS));
    FOR(j, ANS.size()) cout << ANS[j] + 1 << " \n"[i == ANS.size() - 1];
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

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}