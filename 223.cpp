#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
#define all(x) x.begin(), x.end()

void print(i128 x) {
    if (x == 0) {
        cout << "0\n";
        return;
    }
    string res;
    while (x > 0) {
        res += '0' + (x % 10);
        x /= 10;
    }
    reverse(all(res));
    cout << res << endl;
}

const int infty = 1e9;
string S, T;
int N;
i128 DP[51][51][51];
bool vis[51][51][51];
i128 dp(int i, int j, int L) {
    if (L == 0) return 1;
    if (vis[i][j][L]) return DP[i][j][L];
    i128 ret = 0;
    for (int k = 0; k < L; ++k) {
        if (S[i] == T[j + k]) {
            ret += dp(i + 1, j, k) * dp(i + k + 1, j + k + 1, L - k - 1);
        }
    }
    vis[i][j][L] = 1;
    return DP[i][j][L] = ret;
}

void solve() {
    cin >> S >> T;
    N = S.size();
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
            for (int L = 0; L <= N; ++L)
                vis[i][j][L] = 0;
    print(dp(0, 0, N));
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
