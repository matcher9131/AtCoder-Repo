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
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
    }

    vector<pair<ll, ll>> dir = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

    vector<string> t(h, string(w, '.'));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                for (const auto &[di, dj] : dir) {
                    ll ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                    if (s[ni][nj] == '.') t[ni][nj] = '#';
                }
            }
        }
    }
    s = move(t);

    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    queue<pair<ll, ll>> que;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                dist[i][j] = 0;
                que.emplace(i, j);
            }
        }
    }
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (const auto &[di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (dist[ni][nj] < INF) continue;
            dist[ni][nj] = dist[i][j] + 1;
            que.emplace(ni, nj);
        }
    }

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cout << (dist[i][j] % 2 == 0 ? '.' : '#');
        }
        cout << "\n";
    }

    return 0;
}