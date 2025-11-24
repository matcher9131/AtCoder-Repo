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
    ll h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    ll si = -1, sj = -1;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }

    vector<pair<ll, ll>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    dist[si][sj] = 0;
    queue<pair<ll, ll>> que;
    que.emplace(si, sj);
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

    vector<vector<ll>> dist2(h, vector<ll>(w, INF));
    queue<pair<ll, ll>> que2;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (dist[i][j] <= k) {
                dist2[i][j] = 0;
                que2.emplace(i, j);
            }
        }
    }
    while (!que2.empty()) {
        auto [i, j] = que2.front();
        if (i == 0 || i == h-1 || j == 0 || j == w-1) {
            cout << (dist2[i][j] + k-1) / k + 1 << endl;
            return 0;
        }
        que2.pop();
        for (const auto &[di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (dist2[ni][nj] < INF) continue;
            dist2[ni][nj] = dist2[i][j] + 1;
            que2.emplace(ni, nj);
        }
    }

    return 0;
}