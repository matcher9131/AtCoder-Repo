#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    vector<ll> roots;
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            roots.push_back(i);
        } else {
            --a;
            --b;
            g[a].push_back(i);
            g[b].push_back(i);
        }
    }

    vector<bool> visited(n);
    function<void(ll)> dfs = [&](ll from) -> void {
        visited[from] = true;
        for (const ll to : g[from]) {
            if (visited[to]) continue;
            dfs(to);
        }
    };
    for (const ll root : roots) {
        if (!visited[root]) dfs(root);
    }

    cout << count(visited.begin(), visited.end(), true) << endl;

    return 0;
}