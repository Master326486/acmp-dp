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
    int N; cin >> N;
    vector<string> Ax(N); for (auto& x : Ax) cin >> x;
    vector<ll> A(N);
    FOR(i, N) {
        ll sec = 0;
        if (Ax[i][1] == ':') {
            sec += (Ax[i][0] - '0') * 60 * 60;
            sec += (10 * (Ax[i][2] - '0') + (Ax[i][3] - '0')) * 60;
            sec += (10 * (Ax[i][5] - '0') + (Ax[i][6] - '0'));
        }
        else {
            sec += (10 + (Ax[i][1] - '0')) * 60 * 60;
            sec += (10 * (Ax[i][3] - '0') + (Ax[i][4] - '0')) * 60;
            sec += (10 * (Ax[i][6] - '0') + (Ax[i][7] - '0'));
        }
        A[i] = sec;
    }
    sort(all(A));
    vector<ll> suff(N);
    vector<ll> pref(N);
    FOR_R(i, N - 1) suff[i] = suff[i + 1] + 13 * 3600 - A[i + 1];
    FOR(i, 1, N) pref[i] = pref[i - 1] + (A[i] - A[i - 1]) * i;
    vector<ll> dp(N); dp[N - 1] = pref[N - 1];
    FOR_R(i, N - 1) {
        if (A[i] == A[i + 1]) dp[i] = dp[i + 1];
        else dp[i] = pref[i] + suff[i] + (N - i - 1) * (A[i] - 3600);
    }
    //cout << dp[0] << ' ' << dp[1] << ' ' << dp[N - 1];
    //cout << endl;
    string S;
    ll x = A[distance(dp.begin(), min_element(all(dp)))];
    if (x / 3600 > 9) {
        S += '1';
        S += '0' + (x / 3600) - 10;
    }
    else S += '0' + (x / 3600);
    x %= 3600;
    S += ':';
    S += '0' + x / 60 / 10;
    S += '0' + x / 60 % 10;
    x %= 60;
    S += ':';
    S += '0' + x / 10;
    S += '0' + x % 10;
    cout << S << endl;
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