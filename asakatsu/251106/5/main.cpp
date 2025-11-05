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
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<ll> subtreeSumCost(n);
    ll f = 0;
    auto dfs = [&](auto dfs, ll from, ll parent, ll depth) -> void {
        f += depth * c[from];
        for (const ll to : g[from]) {
            if (to == parent) continue;
            dfs(dfs, to, from, depth+1);
        }
        subtreeSumCost[from] = c[from];
        for (const ll to : g[from]) {
            if (to == parent) continue;
            subtreeSumCost[from] += subtreeSumCost[to];
        }
    };
    dfs(dfs, 0, -1, 0);

    ll ans = f;
    auto dfs2 = [&](auto dfs2, ll from, ll parent, ll val) -> void {
        for (const ll to : g[from]) {
            if (to == parent) continue;
            ll newVal = val + subtreeSumCost[0] - 2*subtreeSumCost[to];
            chmin(ans, newVal);
            dfs2(dfs2, to, from, newVal);
        }
    };
    dfs2(dfs2, 0, -1, f);

    cout << ans << endl;

    return 0;
}