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
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    ll si = -1, sj = -1, gi = -1, gj = -1;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (s[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }

    vector<pair<ll, ll>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<vector<ll>>> dist(2, vector<vector<ll>>(h, vector<ll>(w, INF)));
    dist[0][si][sj] = 0;
    queue<tuple<ll, ll, ll>> que;
    que.emplace(0, si, sj);
    while (!que.empty()) {
        auto [k, i, j] = que.front();
        que.pop();
        for (const auto &[di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#' || (k == 0 && s[ni][nj] == 'x') || (k == 1 && s[ni][nj] == 'o')) continue;
            ll nk = s[ni][nj] == '?' ? !k : k;
            if (dist[nk][ni][nj] < INF) continue;
            dist[nk][ni][nj] = dist[k][i][j] + 1;
            que.emplace(nk, ni, nj);
        }
    }
    ll ans = min(dist[0][gi][gj], dist[1][gi][gj]);
    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}