#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;
        for (const ll nv : g[v]) {
            ll cost = h[nv] > h[v] ? h[nv] - h[v] : 0;
            if (dist[v] + cost < dist[nv]) {
                dist[nv] = dist[v] + cost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    ll ans = 0;
    for (ll i = 1; i < n; ++i) {
        ans = max(ans, h[0] - h[i] - dist[i]);
    }
    cout << ans << endl;
    
    return 0;
}