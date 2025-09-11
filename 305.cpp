#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
#define all(x) x.begin(), x.end()

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<bool>> A(N, vector<bool>(M));
    for (int i = 0, x1, y1, x2, y2; i < K; ++i) {
        cin >> x1 >> y1 >> x2 >> y2; --x1, --y1, --x2, --y2;
        for (int x = x1 - 1; x <= x2 + 1; ++x)
            for (int y = y1 - 1; y <= y2 + 1; ++y)
                if (x >= 0 && y >= 0 && x < N && y < M)
                    A[x][y] = 1;
    }
    vector<int> H(M, 0), st;
    int ANS = 0, ans;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!A[i][j]) ++H[j];
            else H[j] = 0;
        }
        ans = 0;
        st.clear();
        for (int x = 0, cur, h, L; x <= M; ++x) {
            cur = (x == M ? 0 : H[x]);
            while (!st.empty() && cur < H[st.back()]) {
                h = H[st.back()];
                st.pop_back();
                L = (st.empty() ? 0 : st.back() + 1);
                ans = max(ans, h * (x - L));
            }
            st.emplace_back(x);
        }
        ANS = max(ANS, ans);
    }
    cout << ANS << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r+", stdin);
    clock_t start_time = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    //int t; cin >> t;
    //while(t--)
        solve();
    cout.flush();

#ifdef LOCAL
    fprintf(stderr, "\n>> Exec Time: %.3f ms\n", (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000);
#endif
    return 0;
}