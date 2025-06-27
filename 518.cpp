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

vector<ll> di = { 1, -1, 0, 0 };
vector<ll> dj = { 0, 0, 1, -1 };
void solve() {
    ll N, K; cin >> N >> K;
    vector<string> G(N); for (auto& x : G) cin >> x;
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(K + 1, 0)));
    auto check = [&](ll i, ll j) -> bool {
        return 0 <= i && i < N && 0 <= j && j < N && G[i][j] == '0';
        };
    deque<tuple<ll, ll, ll>> q;
    q.emplace_back(0, 0, 0);
    dp[0][0][0] = 1;
    ll i, j, k, ni, nj;
    while (!q.empty()) {
        i = get<0>(q.back());
        j = get<1>(q.back());
        k = get<2>(q.back());
        q.pop_back();
        if (k == K) continue;
        FOR(f, 4) {
            ni = i + di[f], nj = j + dj[f];
            //if (i == 1 && j == 1 && f == 0) cout << ni << ' ' << nj << ' ' << k + 1 << endl;
            if (check(ni, nj)) {
                //cout << ni << ' ' << nj << ' ' << k + 1 << endl;
                if (dp[ni][nj][k + 1] == 0) q.emplace_front(ni, nj, k + 1);
                dp[ni][nj][k + 1] += dp[i][j][k];
            }
        }
    }
    //cout << (check(2LL, 1LL) ? "YES" : "NO") << endl;
    //FOR(f, 4) {
    //    cout << di[f] << ' ' << dj[f] << endl;
    //}
    //for (auto& x : dp) {
    //    for (auto& y : x) {
    //        cout << y[4] << ' ';
    //    }
    //    cout << endl;
    //}
    cout << dp[N - 1][N - 1][K] << endl;
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