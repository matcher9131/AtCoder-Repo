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
    vector<pair<ll, ll>> garbage;
    ll ti = -1, tj = -1;
    for (ll i = 0; i < h; ++i) {
        cin >> s[i];
        for (ll j = 0; j < w; ++j) {
            if (s[i][j] == '#') garbage.emplace_back(i, j);
            else if (s[i][j] == 'T') {
                ti = i;
                tj = j;
            }
        }
    }

    auto cond = [&](tuple<ll, ll, ll, ll, ll, ll> state) -> ll {
        auto [u, d, l, r, di, dj] = state;
        bool cleared = true;
        ll dir = 15;
        for (const auto &[i, j] : garbage) {
            if (i < u || i >= h-d || j < l || j >= w-r) continue;
            cleared = false;
            if (i+di == ti+1 && j+dj == tj) dir ^= 1;
            if (i+di == ti-1 && j+dj == tj) dir ^= 2;
            if (i+di == ti && j+dj == tj+1) dir ^= 4;
            if (i+di == ti && j+dj == tj-1) dir ^= 8;
        }
        return cleared ? -1 : dir;
    };

    map<tuple<ll, ll, ll, ll, ll, ll>, ll> dist;
    dist[{0,0,0,0,0,0}] = 0;
    queue<tuple<ll, ll, ll, ll, ll, ll>> que;
    que.push({0,0,0,0,0,0});
    while (!que.empty()) {
        auto state = que.front();
        que.pop();
        ll res = cond(state);
        if (res == -1) {
            cout << dist[state] << endl;
            return 0;
        }
        auto [u, d, l, r, di, dj] = state;
        if (res & 1) {
            tuple<ll, ll, ll, ll, ll, ll> newState = {max(u, -(di-1)), d, l, r, di-1, dj};
            if (!dist.contains(newState)) {
                dist[newState] = dist[state] + 1;
                que.push(newState);
            }
        }
        if (res & 2) {
            tuple<ll, ll, ll, ll, ll, ll> newState = {u, max(d, di+1), l, r, di+1, dj};
            if (!dist.contains(newState)) {
                dist[newState] = dist[state] + 1;
                que.push(newState);
            }
        }
        if (res & 4) {
            tuple<ll, ll, ll, ll, ll, ll> newState = {u, d, max(l, -(dj-1)), r, di, dj-1};
            if (!dist.contains(newState)) {
                dist[newState] = dist[state] + 1;
                que.push(newState);
            }
        }
        if (res & 8) {
            tuple<ll, ll, ll, ll, ll, ll> newState = {u, d, l, max(r, dj+1), di, dj+1};
            if (!dist.contains(newState)) {
                dist[newState] = dist[state] + 1;
                que.push(newState);
            }
        }
    }
    cout << -1 << endl;

    return 0;
}