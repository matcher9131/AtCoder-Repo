#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;

    vector<tuple<ll, ll, ll>> edge;
    edge.reserve(n * (n-1) / 2);
    vector<vector<ll>> distMap(n, vector<ll>(n));
    for (ll i = 0; i < n-1; ++i) {
        for (ll j = i+1; j < n; ++j) {
            ll c;
            cin >> c;
            edge.emplace_back(c, i, j);
            distMap[i][j] = distMap[j][i] = c;
        }
    }
    sort(edge.begin(), edge.end());

    atcoder::dsu d(n);
    vector<vector<pair<ll, ll>>> g(n);
    ll edge_count = 0;
    for (const auto &[c, i, j] : edge) {
        if (edge_count >= n-1) break;
        if (d.same(i, j)) continue;
        d.merge(i, j);
        g[i].emplace_back(j, c);
        g[j].emplace_back(i, c);
        ++edge_count;
    }

    auto distCheck = [&](ll root) -> bool {
        vector<ll> dist(n, -1);
        dist[root] = 0;
        auto dfs = [&](auto dfs, ll from, ll weight) -> bool {
            dist[from] = weight;
            for (const auto &[to, w] : g[from]) {
                if (dist[to] >= 0) continue;
                if (distMap[root][to] != weight + w) return false;
                bool result = dfs(dfs, to, weight + w);
                if (!result) return false;
            }
            return true;
        };
        return dfs(dfs, root, 0);
    };

    for (ll i = 0; i < n; ++i) {
        if (!distCheck(i)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}