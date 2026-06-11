#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()

const int infty = 1e9;
void solve() {
    ll N, K; cin >> N >> K;
    ll W, Dw, S; cin >> W >> Dw >> S;
    vector<bool> good(N + 1, 1);
    vector<bool> goodW(W + 1, 1);
    for (int i = 0; i < Dw; ++i) {
        int d; cin >> d;
        goodW[d] = 0;
    }
    ll Dm; cin >> Dm;
    for (int i = 0; i < Dm; ++i) {
        int d; cin >> d;
        good[d] = 0;
    }
    for (int d = 1; d <= N; ++d) {
        if (!goodW[S]) good[d] = 0;
        ++S;
        if (S == W + 1) S = 1;
    }
    ll ANS = 0, cur = 0;
    for (int d = 1; d <= N; ++d) {
        if (good[d]) ++cur;
        else {
            ANS += max(cur - K + 1, 0LL);
            cur = 0;
        }
    }
    ANS += max(cur - K + 1, 0LL);
    cout << ANS << endl;
}

int main () {
#ifdef LOCAL
    (void)!freopen("input.txt", "r+", stdin);
    clock_t start = clock();
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
#ifdef LOCAL
    cin >> T;
#endif
    while (T --> 0) solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", double(clock() - start) / CLOCKS_PER_SEC * 1000);
#endif

    return 0;
}
