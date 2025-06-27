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
    vector<vector<int>> cnt(6, vector<int>(6));
    vector<int> D(400);
    D['S'] = 1;
    D['W'] = 2;
    D['E'] = 3;
    D['U'] = 4;
    D['D'] = 5;
    FOR(i, 6) {
        string s;
        getline(cin, s);
        for (auto& x : s) if (x - '0' != -35) ++cnt[i][D[x]];
    }
    char X; int Y; cin >> X >> Y;
    vector<ll> dp1(6, 1), dp2; // D(i) leads to how many steps
    //for (auto& x : dp1) cout << x << ' ';
    //cout << endl;
    FOR(i, 2, Y + 1) {
        dp2.assign(6, 1);
        FOR(j, 6) FOR(k, 6) dp2[j] += cnt[j][k] * dp1[k];
        swap(dp1, dp2);
        //for (auto& x : dp1) cout << x << ' ';
        //cout << endl;
    }
    cout << dp1[D[X]] << endl;
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