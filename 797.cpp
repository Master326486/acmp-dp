#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()

const int infty = 1e9;
struct State {
    int y, x, p;
};

int get_mask(int y, int x, int p, int K, const vector<pair<int, int>>& A) {
    int newp = p;
    for (int i = 0; i < K; ++i) {
        if (y + i < 50) {
            if (A[y + i].first != -1 && x <= A[y + i].first && A[y + i].first < x + K) {
                newp &= ~(1 << (2 * i));
            }
            if (A[y + i].second != -1 && x <= A[y + i].second && A[y + i].second < x + K) {
                newp &= ~(1 << (2 * i + 1));
            }
        }
    }
    return newp;
}

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<pair<int, int>> A(50, { -1, -1 });
    int Y = -1;
    for (int i = 0, x, y; i < N; ++i) {
        cin >> x >> y; --x, --y;
        if (A[y].first > x || A[y].first == -1) A[y].first = x;
        if (A[y].second < x || A[y].second == -1) A[y].second = x;
        Y = max(Y, y);
    }

    if (Y == -1) {
        cout << 0 << "\n";
        return;
    }

    int num_masks = 1 << (2 * K);
    vector<vector<vector<short>>> dist(50, vector<vector<short>>(50, vector<short>(num_masks, -1)));

    int X = 0;
    for (int i = 0; i < K; ++i) {
        if (i < 50) {
            if (A[i].first != -1 && !(0 <= A[i].first && A[i].first < K)) {
                X |= (1 << (2 * i));
            }
            if (A[i].second != -1 && !(0 <= A[i].second && A[i].second < K)) {
                X |= (1 << (2 * i + 1));
            }
        }
    }

    queue<State> q;
    dist[0][0][X] = 0;
    q.push({0, 0, X});

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        int y = curr.y;
        int x = curr.x;
        int p = curr.p;
        int d = dist[y][x][p];

        if (x > 0) {
            int nx = x - 1;
            int np = get_mask(y, nx, p, K, A);
            if (dist[y][nx][np] == -1) {
                dist[y][nx][np] = d + 1;
                q.push({y, nx, np});
            }
        }

        if (x < 49) {
            int nx = x + 1;
            int np = get_mask(y, nx, p, K, A);
            if (dist[y][nx][np] == -1) {
                dist[y][nx][np] = d + 1;
                q.push({y, nx, np});
            }
        }

        if (y < 49 && (p & 3) == 0) {
            int ny = y + 1;
            int np = p >> 2;
            
            if (ny + K - 1 < 50) {
                int row = ny + K - 1;
                if (A[row].first != -1 && !(x <= A[row].first && A[row].first < x + K)) {
                    np |= (1 << (2 * K - 2));
                }
                if (A[row].second != -1 && !(x <= A[row].second && A[row].second < x + K)) {
                    np |= (1 << (2 * K - 1));
                }
            }
            if (dist[ny][x][np] == -1) {
                dist[ny][x][np] = d + 1;
                q.push({ny, x, np});
            }
        }
    }

    int ans = infty;
    int start_y = max(0, Y - K + 1);
    for (int y = start_y; y < 50; ++y) {
        for (int x = 0; x < 50; ++x) {
            if (dist[y][x][0] != -1) {
                ans = min(ans, (int)dist[y][x][0]);
            }
        }
    }

    cout << ans << "\n";
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
