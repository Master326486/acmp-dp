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
    u32 N, M, R; cin >> N >> M >> R;
    vector<vector<u32>> A(3, vector<u32>(M, 0));
    FOR(i, M) {
        cin >> A[0][i];
        A[0][i] %= R;
    }
    auto add = [&](ll i, ll j, ll x) -> void {
        A[i][j] += x;
        if (A[i][j] >= R) A[i][j] -= R;
        };
    FOR(I, 1, N) {
        ll i = min(I, 2LL);
        FOR(j, M) {
            A[i][j] = 0;
            if (j > 0) add(i, j, A[i - 1][j - 1]);
            if (I > 1 && j > 0) add(i, j, A[i - 1][j - 1]);
            if (j < M - 1) add(i, j, A[i - 1][j + 1]);
            if (I > 1 && j < M - 1) add(i, j, A[i - 1][j + 1]);
            if (j < M - 1 && j > 0 && I > 1) add(i, j, R - A[i - 2][j]);
            if (j < M - 1 && j > 0 && I > 2) add(i, j, R - A[i - 2][j]);
            add(i, j, A[i - 1][j]);
        }
        if (I > 1) {
            swap(A[0], A[1]);
            swap(A[1], A[2]);
        }
    }
    FOR(i, M) cout << A[1][i] << " \n"[i == M - 1];
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