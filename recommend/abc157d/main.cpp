#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<ll>> block(n);
    for (ll i = 0; i < k; ++i) {
        ll c, d;
        cin >> c >> d;
        --c; --d;
        block[c].push_back(d);
        block[d].push_back(c);
    }

    vector<bool> visited(n);
    function<void(ll,unordered_set<ll>&)> dfs = [&](ll from, unordered_set<ll> &group) -> void {
        visited[from] = true;
        group.insert(from);
        for (const ll to : g[from]) {
            if (visited[to]) continue;
            dfs(to, group);
        }
    };

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        if (!visited[i]) {
            unordered_set<ll> group;
            dfs(i, group);
            for (const ll v : group) {
                ans[v] = (ll)group.size() - (ll)g[v].size() - 1;
                for (const ll u : block[v]) {
                    if (group.contains(u)) --ans[v];
                }
            }
        }
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }
    return 0;
}