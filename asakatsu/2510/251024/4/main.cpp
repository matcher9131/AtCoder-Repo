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
    vector<vector<pair<ll, pair<ll, ll>>>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        --a; --b;
        g[a].emplace_back(b, make_pair(x, y));
        g[b].emplace_back(a, make_pair(-x, -y));
    }

    pair<ll, ll> UNDEFINED = {INF, INF};
    vector<pair<ll, ll>> coord(n, UNDEFINED);
    auto dfs = [&](auto dfs, ll from, pair<ll, ll> c) -> void {
        coord[from] = c;
        for (const auto &[to, v] : g[from]) {
            if (coord[to] != UNDEFINED) continue;
            dfs(dfs, to, {c.first + v.first, c.second + v.second});
        }
    };
    dfs(dfs, 0, {0, 0});

    for (ll i = 0; i < n; ++i) {
        if (coord[i] == UNDEFINED) {
            cout << "undecidable\n";
        } else {
            cout << coord[i].first << " " << coord[i].second << "\n";
        }
    }

    return 0;
}