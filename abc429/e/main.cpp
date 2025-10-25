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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string s;
    cin >> s;

    
    // 安全頂点No, 距離
    vector<vector<pair<ll, ll>>> dist(n);
    auto isVisited = [&](ll to, ll src) -> bool {
        for (const auto &[s, _] : dist[to]) {
            if (s == src) return true;
        }
        return false;
    };
    // 頂点, 距離, どの安全頂点から
    queue<tuple<ll, ll, ll>> que;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'S') {
            que.emplace(i, 0, i);
            dist[i].emplace_back(i, 0);
        }
    }
    while (!que.empty()) {
        auto [from, d, src] = que.front();
        que.pop();
        for (const ll to : g[from]) {
            if (isVisited(to, src)) continue;
            if ((ll)dist[to].size() < 2) {
                dist[to].emplace_back(src, d+1);
                que.emplace(to, d+1, src);
            } else {
                auto it = max_element(dist[to].begin(), dist[to].end(), [](auto &x, auto &y) { return x.second < y.second; });
                if (d+1 < it->second) {
                    *it = { src, d+1 };
                    que.emplace(to, d+1, src);
                }
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'S') continue;
        cout << dist[i][0].second + dist[i][1].second << endl;
    }

    return 0;
}