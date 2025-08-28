#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define all(x) x.begin(), x.end()

bool comp(pair<int, int>& x, pair<int, int>& y) {
    return x.first > y.first || (x.first == y.first && x.second < y.second);
}
void solve() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (auto& x : A) for (auto& y : x) cin >> y;
    vector<vector<int>> place(N, vector<int>(N)), want(N, vector<int>(N));
    vector<pair<int, int>> tmp(N);
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            tmp[i].first = A[i][j];
            tmp[i].second = i;
        }
        sort(all(tmp), comp);
        for (int i = 0; i < N; ++i)
            place[j][tmp[i].second] = i;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tmp[j].first = A[i][j];
            tmp[j].second = j;
        }
        sort(all(tmp), comp);
        for (int j = 0; j < N; ++j)
            want[i][j] = tmp[j].second;
    }
    vector<int> taken(N, -1), ntry(N, 0);
    deque<int> q;
    for (int i = 0; i < N; ++i)
        q.emplace_back(i);
    while (!q.empty()) {
        auto i = q.front();
        q.pop_front();
        if (ntry[i] >= N) continue;
        int j = want[i][ntry[i]++];
        if (taken[j] == -1) taken[j] = i;
        else {
            int k = taken[j];
            if (place[j][i] < place[j][k]) {
                taken[j] = i;
                q.emplace_back(k);
            }
            else q.emplace_back(i);
        }
    }
    vector<int> ANS(N);
    for (int i = 0; i < N; ++i) ANS[taken[i]] = i + 1;
    for (int i = 0; i < N; ++i)
        cout << ANS[i] << " \n"[i == N - 1];
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