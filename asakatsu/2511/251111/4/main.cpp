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

    vector<pair<ll, ll>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto isTarget = [&](int i, int j) -> bool {
        ll count = 0;
        for (const auto &[di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s[ni][nj] == '#') ++count;
        }
        return count == 1;
    };

    queue<pair<ll, ll>> que;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                que.emplace(i, j);
            }
        }
    }
    while (!que.empty()) {
        vector<pair<ll, ll>> targets;
        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (const auto &[di, dj] : dir) {
                ll ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || s[ni][nj] == '#') continue;
                if (isTarget(ni, nj)) {
                    targets.emplace_back(ni, nj);
                }
            }
        }
        for (const auto &[i, j] : targets) {
            s[i][j] = '#';
            que.emplace(i, j);
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}