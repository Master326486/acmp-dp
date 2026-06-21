#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
#define all(x) x.begin(), x.end()

const int MX = 105;
vector<vector<i128>> C(MX, vector<i128>(MX));
void calc() {
    for (int i = 0; i <= 100; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

void print(i128 x) {
    if (x == 0) {
        cout << "0\n";
        return;
    }
    string ret;
    while (x > 0) {
        ret += '0' + x % 10;
        x /= 10;
    }
    reverse(all(ret));
    cout << ret << "\n";
}

const int infty = 1'000'000'000;
void solve() {
    int M, N, W, B; cin >> M >> N >> W >> B;
    vector<vector<vector<i128>>> dp(M + 1, vector<vector<i128>>(N + 1, vector<i128>(W + 1)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k <= W; ++k) {
                for (int x = 0; x <= j; ++x) {
                    int y = j - x;
                    for (int z = 0; z <= k - x; ++z) if (x + z > 0) {
                        int pk = k - x - z;
                        if (x <= N - y && z <= y)
                            dp[i][j][k] += dp[i - 1][y][pk] * C[y][z] * C[N - y][x];
                    }
                }
            }
        }
    }
    i128 ANS = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            i128 x = C[M][i] * dp[i][j][W];
            if (x == 0) continue;
            int b = (M - i) * (N - j);
            if (b >= B)
                ANS += x * C[b][B];
        }
    }
    print(ANS);
}

int main () {
#ifdef LOCAL
    (void)!freopen("input.txt", "r+", stdin);
    clock_t start = clock();
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    calc();
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
