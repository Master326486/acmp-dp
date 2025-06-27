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

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))

template <typename T = int>
vector<T> primetable(int LIM) {
    ++LIM;
    const int S = 32768;
    static int done = 2;
    static vector<T> primes = { 2 }, sieve(S + 1);

    if (done < LIM) {
        done = LIM;

        primes = { 2 }, sieve.assign(S + 1, 0);
        const int R = LIM / 2;
        primes.reserve(int(LIM / log(LIM) * 1.1));
        vector<pair<int, int>> cp;
        for (int i = 3; i <= S; i += 2) {
            if (!sieve[i]) {
                cp.emplace_back(i, i * i / 2);
                for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
            }
        }
        for (int L = 1; L <= R; L += S) {
            array<bool, S> block{};
            for (auto& [p, idx] : cp)
                for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;
            FOR(i, min(S, R - L)) if (!block[i]) primes.emplace_back((L + i) * 2 + 1);
        }
    }
    int k = LB(primes, LIM + 1);
    return { primes.begin(), primes.begin() + k };
}

const ll MOD = 1'000'000'009;
void solve() {
    ll N; cin >> N;
    auto ptt = primetable<ll>(1001);
    vector<ll> pt; for (auto& x : ptt) if (100 <= x && 1000 > x) pt.emplace_back(x);
    vector<vector<vector<ll>>> source(10, vector<vector<ll>>(10));
    for (auto& x : pt) {
        source[x / 100][(x / 10) % 10].emplace_back(x % 10);
    }
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(10, vector<ll>(10)));
    for (auto& x : pt) {
        ++dp[3][(x / 10) % 10][x % 10];
    }
    FOR(i, 3, N) {
        FOR(j, 1, 10) FOR(k, 10) {
            for (auto& x : source[j][k]) dp[i + 1][k][x] = (dp[i + 1][k][x] + dp[i][j][k]) % MOD;
        }
    }
    ll ANS = 0;
    FOR(i, 10) FOR(j, 10) ANS = (ANS + dp[N][i][j]) % MOD;
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