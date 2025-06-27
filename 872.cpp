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
    vector<string> Ax(N); for (auto& x : Ax) cin >> x;
    sort(all(Ax));
    vector<string> A; A.emplace_back(Ax[0]); for (auto& x : Ax) if (x != A.back()) A.emplace_back(x);
    N = A.size();
    sort(all(A), [](const string& a, const string& b) { return a.size() < b.size(); });

    vector<vector<bool>> issub(N, vector<bool>(N)); // issub[i][j] = A[i] is sub of A[j]?
    FOR(i, N) FOR(j, N) if (i != j && A[i].size() < A[j].size()) {
        bool t = 1;
        FOR(k, A[i].size()) if (A[i][k] != A[j][k]) { t = 0; break; }
        issub[i][j] = t;
    }

    vector<set<ll>> dp1(N + 1), dp2;
    FOR(i, N) dp1[1].insert(i);
    FOR(i, N) {
        dp2 = dp1;
        FOR(j, 1, N) {
            for (auto& idx : dp1[j]) if (issub[idx][i]) dp2[j + 1].insert(i);
        }
        swap(dp2, dp1);
    }
    ll ANS = 0;
    FOR(i, 1, N + 1) if (!dp1[i].empty()) ANS = i;
    cout << ANS << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r+", stdin);
    clock_t start_time = clock();
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    solve();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}