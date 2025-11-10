#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    ll si, sj;
    cin >> si >> sj;
    --si;
    --sj;
    ll gi, gj;
    cin >> gi >> gj;
    --gi;
    --gj;
    if ((si+sj)%2 != (gi+gj)%2) {
        cout << -1 << endl;
        return 0;
    }

    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<pair<ll, ll>> dir = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    // 0: 右下, 1: 右上, 2: 左上, 3: 左下
    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(n, vector<ll>(4, INF)));
    deque<tuple<ll, ll, ll>> que;
    for (ll k = 0; k < 4; ++k) {
        dist[si][sj][k] = 0;
        que.emplace_back(si, sj, k); 
    }
    while (!que.empty()) {
        auto [i, j, k] = que.front();
        que.pop_front();
        for (ll nk = 0; nk < 4; ++nk) {
            auto [di, dj] = dir[nk];
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= n || nj < 0 || nj >= n || s[ni][nj] == '#') continue;
            ll nd = dist[i][j][k] + (nk != k);
            if (nd >= dist[ni][nj][nk]) continue;
            dist[ni][nj][nk] = nd;
            if (nk == k) que.emplace_front(ni, nj, nk);
            else que.emplace_back(ni, nj, nk);
        }
    }

    ll ans = *min_element(dist[gi][gj].begin(), dist[gi][gj].end());
    cout << (ans == INF ? -1 : ans+1) << endl;

    return 0;
}