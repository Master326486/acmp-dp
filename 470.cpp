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

template <typename E>
struct Monoid_Add {
    using X = E;
    using value_type = X;
    static constexpr X op(const X& x, const X& y) noexcept { return x + y; }
    static constexpr X inverse(const X& x) noexcept { return -x; }
    static constexpr X power(const X& x, ll n) noexcept { return X(n) * x; }
    static constexpr X unit() { return X(0); }
    static constexpr bool commute = true;
};

template <typename Monoid>
struct Cumsum_2D {
    using MX = Monoid;
    static_assert(MX::commute);
    using X = typename MX::value_type;
    int H, W;
    vector<X> dat;

    Cumsum_2D() {}
    Cumsum_2D(vector<vector<X>>& A) { build(A); }

    void build(vector<vector<X>>& A) {
        H = A.size();
        W = (H == 0 ? 0 : A[0].size());
        dat.assign(H * W, MX::unit());
        FOR(x, H) FOR(y, W) {
            int k = W * x + y;
            dat[k] = (y == 0 ? A[x][y] : MX::op(dat[k - 1], A[x][y]));
        }
        FOR(i, W, H * W) dat[i] = MX::op(dat[i - W], dat[i]);
    }

    // [x1,x2) x [y1,y2)
    template <bool allow_out_of_range = false>
    X sum(int x1, int x2, int y1, int y2) {
        if constexpr (allow_out_of_range) {
            x1 = max(x1, 0), x2 = min(x2, H), y1 = max(y1, 0), y2 = min(y2, W);
            if (x1 >= x2 || y1 >= y2) return MX::unit();
        }
        if (x2 == 0 || y2 == 0) return MX::unit();
        assert(0 <= x1 && x1 <= x2 && x2 <= H);
        assert(0 <= y1 && y1 <= y2 && y2 <= W);
        --x1, --y1, --x2, --y2;
        X a = (x1 >= 0 && y1 >= 0 ? dat[W * x1 + y1] : MX::unit());
        X b = (x1 >= 0 && y2 >= 0 ? dat[W * x1 + y2] : MX::unit());
        X c = (x2 >= 0 && y1 >= 0 ? dat[W * x2 + y1] : MX::unit());
        X d = (x2 >= 0 && y2 >= 0 ? dat[W * x2 + y2] : MX::unit());
        return MX::op(MX::op(a, d), MX::inverse(MX::op(b, c)));
    }

    X prefix_sum(int x, int y) {
        return (x == 0 || y == 0) ? MX::unit() : dat[W * x + y - (W + 1)];
    }
};

void solve() {
    ll H, W, N; cin >> H >> W >> N;
    vector<vector<ll>> G(H, vector<ll>(W));
    FOR(i, H) FOR(j, W) cin >> G[i][j];
    auto cs = Cumsum_2D<Monoid_Add<ll>>(G);
    FOR(i, N) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        if (a == c && b == d) {
            cout << G[a - 1][b - 1] << endl;
            continue;
        }
        if (a >= c) swap(a, c);
        if (b >= d) swap(b, d);
        --a, --b;
        cout << cs.sum(a, c, b, d) << endl;
    }
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