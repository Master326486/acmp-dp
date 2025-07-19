#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
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

std::ostream& operator<<(std::ostream & dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

void solve() {
    int N; cin >> N;
    vector<i128> dp1(10, 1), dp2; dp1[8] = 0; dp1[0] = 0;
    vector<pair<int, int>> es;
    es.emplace_back(1, 6);
    es.emplace_back(1, 8);
    es.emplace_back(2, 7);
    es.emplace_back(2, 9);
    es.emplace_back(3, 4);
    es.emplace_back(3, 8);
    es.emplace_back(4, 3);
    es.emplace_back(4, 9);
    es.emplace_back(4, 0);
    es.emplace_back(6, 1);
    es.emplace_back(6, 7);
    es.emplace_back(6, 0);
    es.emplace_back(7, 2);
    es.emplace_back(7, 6);
    es.emplace_back(8, 1);
    es.emplace_back(8, 3);
    es.emplace_back(9, 2);
    es.emplace_back(9, 4);
    es.emplace_back(0, 4);
    es.emplace_back(0, 6);
    FOR(N - 1) {
        dp2.assign(10, 0);
        for (auto& [frm, to] : es) dp2[to] += dp1[frm];
        swap(dp1, dp2);
    }
    i128 ans = 0;
    FOR(i, 10) ans += dp1[i];
    cout << ans << endl;
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