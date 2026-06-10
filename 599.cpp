#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()

const int infty = 1e9;
void solve() {
    int N; cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; ++i) {
        char x; cin >> x;
        L[i] = x - 'a';
    }
    vector<ll> cntl(26), cntr(26), S(26);
    for (int i = 0; i < N; ++i) {
        if (i <= N / 2 && i != 0) ++cntr[L[i]];
        else if ((N & 1) && i == (N + 1) / 2);
        else ++cntl[L[i]];
        S[L[i]] += min(i, N - i);
    }
    ll ANS = 0, ANS2 = 1;
    for (int i = 0; i < 26; ++i) ANS += S[i] * abs(L[0] - i);
    for (int i = 1; i < N; ++i) {
        ll cur = 0;
        for (int j = 0; j < 26; ++j) {
            S[j] += cntl[j] - cntr[j];
            cur += S[j] * abs(L[i] - j);
        }
        --cntr[L[i]]; ++cntl[L[i]];
        if (N & 1) {
            ++cntr[L[(i + N / 2) % N]]; 
            --cntl[L[(i + (N + 1) / 2) % N]];
        } else {
            ++cntr[L[(i + N / 2) % N]];
            --cntl[L[(i + N / 2) % N]];
        }
        if (cur > ANS) {
            ANS = cur;
            ANS2 = i + 1;
        }
    }
    cout << ANS << endl << ANS2 << endl;
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
