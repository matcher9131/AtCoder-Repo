#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> g1(h);
    ll si = 0, sj = 0, gi = 0, gj = 0;
    for (ll i = 0; i < h; ++i) {
        cin >> g1[i];
        for (ll j = 0; j < w; ++j) {
            if (g1[i][j] == 'S') {
                si = i;
                sj = j;
            }
            else if (g1[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }

    vector<string> g2 = g1;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (g1[i][j] == 'o') g2[i][j] = 'x';
            else if (g1[i][j] == 'x') g2[i][j] = 'o';
        }
    }

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<vector<ll>>> dist(2, vector<vector<ll>>(h, vector<ll>(w, INF)));
    dist[0][si][sj] = 0;
    // f, i, j
    queue<tuple<ll, ll, ll>> que;
    que.emplace(0, si, sj);
    while (!que.empty()) {
        auto [f, i, j] = que.front();
        que.pop();
        if (i == gi && j == gj) break;
        auto &g = f ? g2 : g1;
        for (const auto &[di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || g[i][j] == '#' || g[i][j] == 'x') continue;
            ll nf = g[ni][nj] == '?' ? (!f) : f;
            if (dist[nf][ni][nj] < INF) continue;
            dist[nf][ni][nj] = dist[f][i][j] + 1;
            que.emplace(nf, ni, nj);
        }
    }

    ll ans = min(dist[0][gi][gj], dist[1][gi][gj]);
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
}
