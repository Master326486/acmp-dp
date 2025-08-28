#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()

void solve() {
    int A, B, C, K; cin >> A >> B >> C >> K;
    auto isin = [&](int x, int y, int z) -> bool {
        if (x < 0 || x > A) return false;
        if (y < 0 || y > B) return false;
        if (z < 0 || z > C) return false;
        return true;
        };
    vector<vector<vector<pair<int, int>>>> dist(A + 1, vector<vector<pair<int, int>>>(B + 1, vector<pair<int, int>>(C + 1)));
    deque<tuple<int, int, int>> q;
    q.emplace_back(0, 0, 0);
    int dx[] = { 0, 0, 1 };
    int dy[] = { 0, 1, 0 };
    int dz[] = { 1, 0, 0 };
    pair<int, int> nd;
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop_front();
        int k = dist[x][y][z].second;
        for (int i = 0, nx, ny, nz, nk; i < 3; ++i) {
            nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if (!isin(nx, ny, nz)) continue;
            nk = k + dx[i] + dy[i] * 2 + dz[i] * 3;
            nd = dist[x][y][z];
            nd.second = nk;
            if (nk >= K) {
                nd.first += 1;
                nd.second = 0;
            }
            if (dist[nx][ny][nz] < nd) {
                dist[nx][ny][nz] = nd;
                q.emplace_back(nx, ny, nz);
            }
        }
    }
    cout << dist[A][B][C].first << endl;
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