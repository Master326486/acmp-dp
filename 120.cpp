#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

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

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

bool multicase = 0;
void solve() {
    ll N, M; cin >> N >> M;
    vv(ll, A, N, M); FOR(i, N) FOR(j, M) cin >> A[i][j];
    vv(ll, dp, N, M, 1'000'000'000LL);
    dp[0][0] = A[0][0];
    FOR(i, N) FOR(j, M) {
        if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i][j]);
        if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + A[i][j]);
    }
    //for (auto& x : A) {
    //    for (auto& y : x) cout << y << ' ';
    //    cout << endl;
    //}
    cout << dp[N - 1][M - 1] << endl;
}

signed main()
{
 //   freopen("input.txt", "r+", stdin);
    int T = 1;
    if (multicase) cin >> T;
    FOR(T) solve();

    return 0;
}
