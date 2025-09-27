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

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<ll, ll>> que;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                que.emplace(i, j);
            }
        }
    }
    while (!que.empty()) {
        vector<pair<ll, ll>> tmp;
        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            s[i][j] = '#';
            for (const auto &[di, dj] : dir) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
                ll count = 0;
                for (const auto &[di2, dj2] : dir) {
                    ll ni2 = ni + di2, nj2 = nj + dj2;
                    if (ni2 < 0 || ni2 >= h || nj2 < 0 || nj2 >= w) continue;
                    if (s[ni2][nj2] == '#') ++count;
                }
                if (count == 1) {
                    tmp.emplace_back(ni, nj);
                }
            }
        }
        for (const auto &[i, j] : tmp) {
            s[i][j] = '#';
            que.emplace(i, j);
        }
    }
    
    ll count = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') ++count;
        }
    }
    cout << count << endl;

    return 0;
}