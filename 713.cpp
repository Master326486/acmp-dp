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
    string S; cin >> S; vector<int> A(4); FOR(i, 4) A[i] = S[i] - '0';
    vector<vector<int>> dp1(2, vector<int>(2, -1)), dp2; // first 0/1 = result, second 0/1 = last digit
    vector<vector<vector<pair<bool, bool>>>> par(N + 1, vector<vector<pair<bool, bool>>>(2, vector<pair<bool, bool>>(2)));
    FOR(i, 2) FOR(j, 2) dp1[A[2 * i + j]][j] = i + j, par[2][A[2 * i + j]][j] = make_pair((bool)i, (bool)i);
    FOR(i, 3, N + 1) {
        dp2.assign(2, vector<int>(2, -1));
        FOR(j, 2) FOR(k, 2) {
            FOR(j2, 2) FOR(k2, 2) {
                if (A[j2 * 2 + k] == j) {
                    if (dp2[j][k] < dp1[j2][k2]) {
                        dp2[j][k] = dp1[j2][k2];
                        par[i][j][k] = make_pair((bool)j2, (bool)k2);
                    }
                }
            }
            if (dp2[j][k] != -1) dp2[j][k] += k;
        }
        swap(dp1, dp2);
    }
    //cout << par.capacity() * sizeof(pair<bool, bool>) << " bytes" << endl;
    //for (auto& x : dp) {
    //    cout << x[0][0] << ' ' << x[0][1] << ' ' << x[1][0] << ' ' << x[1][1] << endl;
    //}
    ll i = N, j = 1, k = 0;
    if (dp1[j][1] == dp1[j][0] && dp1[j][1] == -1) {
        cout << "No solution" << endl; return;
    }
    if (dp1[j][1] > dp1[j][0]) k = 1;
    string ANS;
    while (i > 0) {
        ANS += '0' + k;
        ll x = par[i][j][k].first, y = par[i][j][k].second;
        j = x, k = y; --i;
    }
    reverse(all(ANS));
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

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}
