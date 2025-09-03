#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n+1);
    for (ll i = 0; i < m; ++i) {
        ll l, r;
        cin >> l >> r;
        // [l, r)
        --l;
        g[l].push_back(r);
        g[r].push_back(l);
    }

    vector<bool> visited(n+1);
    function<void(ll)> dfs = [&](ll from) -> void {
        visited[from] = true;
        for (const ll to : g[from]) {
            if (visited[to]) continue;
            dfs(to);
        }
    };
    dfs(0);

    cout << (visited[n] ? "Yes" : "No") << endl;

    return 0;
}