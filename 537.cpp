#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()

const ll infty = 2'000'000'000'000'000'000LL;
int main() {
    int N; ll M, K; cin >> N >> M >> K;
    vector<ll> A(N); for (auto& x : A) cin >> x;
    vector<vector<ll>> dp(1 << N, vector<ll>(N));
    sort(all(A));
    vector<vector<bool>> ok(N, vector<bool>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ok[i][j] = (__gcd(A[i], A[j]) >= K);
    for (int i = 0; i < N; ++i)
        dp[1 << i][i] = 1;
    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int i = 0; i < N; ++i) if ((mask >> i) & 1) {
            for (int j = 0; j < N; ++j) if (((mask >> j) & 1) && i != j && ok[i][j]) {
                dp[mask][i] += dp[mask ^ (1 << i)][j];
            }
        }
    }
    vector<bool> used(N);
    ll tot = 0;
    vector<ll> ANS;
    int mask = (1 << N) - 1;
    for (int i = 0; i < N; ++i) tot += dp[mask][i];
    if (M > tot) {
        cout << -1 << endl;
        return 0;
    }
    int last = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) if (!used[j] && (last == -1 || ok[last][j])) {
            if (M > dp[mask][j]) M -= dp[mask][j];
            else {
                ANS.emplace_back(A[j]);
                used[j] = 1;
                last = j;
                mask ^= (1 << j);
                //cout << A[j] << ' ' << mask << endl;
                break;
            }
        }
    }
    for (int i = 0; i < N; ++i)
        cout << ANS[i] << " \n"[i == N - 1];
}
