#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w;
    cin >> h >> w;
    ll numBlack = 0;
    vector<string> s(h);
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') ++numBlack;
        }
    }

    vector<pair<ll, ll>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    dist[0][0] = 0;
    queue<pair<ll, ll>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (const auto &[di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
            if (dist[ni][nj] < INF) continue;
            dist[ni][nj] = dist[i][j] + 1;
            que.emplace(ni, nj);
        }
    }

    if (dist[h-1][w-1] == INF) {
        cout << -1 << endl;
    } else {
        cout << h*w - numBlack - (dist[h-1][w-1] + 1) << endl;
    }

    return 0;
}