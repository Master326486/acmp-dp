#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
#define all(x) x.begin(), x.end()

string printable(i128 v) {
    string ret;
    while (v) {
        ret += '0' + v % 10;
        v /= 10;
    }
    reverse(all(ret));
    return ret;
}
const ll infty = 2'000'000'000'000'000'000LL;
void solve() {
    ll N; cin >> N;
    vector<i128> ans(4);
    ans[0] = 0; ans[1] = 1; ans[2] = 1;
    if (N <= 2) {
        cout << printable(ans[N]);
        return;
    }
    for (int i = 3; i <= N; ++i) {
        ans[3] = ans[2] + ans[0] + 1;
        ans[0] = ans[1];
        ans[1] = ans[2];
        ans[2] = ans[3];
    }
    cout << printable(ans[3]) << endl;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r+", stdin);
    clock_t start_time = clock();
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    //int T; cin >> T;
    //while (T--)
        solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}
