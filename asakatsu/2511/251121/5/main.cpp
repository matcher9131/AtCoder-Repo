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
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    vector<ll> ans(n, -1);
    auto dfs = [&](auto dfs, ll from, ll x) -> void {
        ans[from] = x;
        for (const auto &[to, w] : g[from]) {
            if (ans[to] != -1) continue;
            ll nx = ans[from] == w ? (w == 1 ? 2 : 1) : w;
            dfs(dfs, to, nx);
        }
    };
    dfs(dfs, 0, 1);

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}