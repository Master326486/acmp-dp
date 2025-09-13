#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
#define all(x) x.begin(), x.end()

void solve() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); for (auto& x : A) cin >> x;
    ll sum = 0; for (auto& x : A) sum += x;
    if (sum < 2 * K) {
        cout << 0 << endl;
        return;
    }
    ll ANS = (1LL << N);
    vector<ll> dp(K); dp[0] = 1;
    for (auto& x : A)
        for (int i = K - 1; i >= x; --i)
            dp[i] += dp[i - x];
    for (auto& x : dp) ANS -= 2 * x;
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
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}