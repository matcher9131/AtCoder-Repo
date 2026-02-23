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
    ll m, a, b;
    cin >> m >> a >> b;

    vector<vector<ll>> g(m*m);
    for (ll x = 0; x < m; ++x) {
        for (ll y = 0; y < m; ++y) {
            ll z = (a*y + b*x) % m;
            g[y + m*z].push_back(x + m*y);
        }
    }

    vector<bool> visited(m*m);
    auto dfs = [&](auto dfs, ll from) -> void {
        visited[from] = true;
        for (const ll to : g[from]) {
            if (visited[to]) continue;
            dfs(dfs, to);
        }
    };
    for (ll y = 0; y < m; ++y) {
        dfs(dfs, m*y);
    }

    ll ans = 0;
    for (ll i = 0; i < m*m; ++i) {
        if (!visited[i]) ++ans;
    }
    cout << ans << endl;

    return 0;
}