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

    ll si = INF, sj = INF, gi = INF, gj = INF;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '<') {
                for (ll j2 = j-1; j2 >= 0; --j2) {
                    if (s[i][j2] == '.' || s[i][j2] == '!') s[i][j2] = '!';
                    else break;
                }
            } else if (s[i][j] == '>') {
                for (ll j2 = j+1; j2 < w; ++j2) {
                    if (s[i][j2] == '.' || s[i][j2] == '!') s[i][j2] = '!';
                    else break;
                }
            } else if (s[i][j] == '^') {
                for (ll i2 = i-1; i2 >= 0; --i2) {
                    if (s[i2][j] == '.' || s[i2][j] == '!') s[i2][j] = '!';
                    else break;
                }
            } else if (s[i][j] == 'v') {
                for (ll i2 = i+1; i2 < h; ++i2) {
                    if (s[i2][j] == '.' || s[i2][j] == '!') s[i2][j] = '!';
                    else break;
                }
            } else if (s[i][j] == 'S') {
                si = i;
                sj = j;
                s[i][j] = '.';
            } else if (s[i][j] == 'G') {
                gi = i;
                gj = j;
                s[i][j] = '.';
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
            if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] != '.') continue;
            if (dist[ni][nj] < INF) continue;
            dist[ni][nj] = dist[i][j] + 1;
            que.emplace(ni, nj);
        }
    }
    cout << (dist[gi][gj] == INF ? -1 : dist[gi][gj]) << endl;

    return 0;
}