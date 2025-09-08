#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

void solve() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    --x;
    --y;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (ll i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }

    vector<vector<ll>> dist(n, {n});
    dist[x] = {x};
    priority_queue<pair<vector<ll>, int>, vector<pair<vector<ll>, int>>, greater<pair<vector<ll>, int>>> que;
    que.emplace(0, x);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const ll nv : g[v]) {
            vector<ll> newCost = dist[v];
            newCost.push_back(nv);
            if (newCost < dist[nv]) {
                dist[nv] = newCost;
                que.emplace(newCost, nv);
            }
        }
    }

    for (ll i = 0; i < (ll)dist[y].size(); ++i) {
        cout << dist[y][i]+1 << " \n"[i == (ll)dist[y].size() - 1];
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }


    return 0;
}