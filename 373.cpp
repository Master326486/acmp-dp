#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K; --K;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> dp1(n, vector<int>(n, 0));
    dp1[0][0] = A[0][0];
    
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    
    for (int _ = 1; _ <= k; ++_) {
        vector<vector<int>> dp2(n, vector<int>(n, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dp1[i][j] == 0) continue;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (0 <= ni && ni < N && 0 <= nj && nj < N) {
                        dp2[ni][nj] = max(dp2[ni][nj], dp1[i][j] + A[ni][nj]);
                    }
                }
            }
        }
        swap(dp1, dp2);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, *max_element(dp1[i].begin(), dp1[i].end()));
    }
    cout << ans << endl;
    
    return 0;
}
