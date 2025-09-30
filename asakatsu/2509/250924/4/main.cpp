#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<ll, ll>>> g(2*n);
    for (ll i = 0; i < n; ++i) {
        g[i].emplace_back(i+n, x);
        g[i+n].emplace_back(i, x);
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].emplace_back(b, 1);
        g[b+n].emplace_back(a+n, 1);
    }

    vector<ll> dist(2*n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const auto& [nv, cost] : g[v]) {
            if (dist[v] + cost < dist[nv]) {
                dist[nv] = dist[v] + cost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    cout << min(dist[n-1], dist[2*n-1]) << endl;

    return 0;
}