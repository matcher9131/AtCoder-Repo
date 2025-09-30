#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

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
    map<ll, ll> next;
    for (const auto &[v, w] : g[0]) next[v] = w;

    ll ans = INF;
    for (const auto &[root, w0] : next) {
        vector<ll> dist(n, INF);
        dist[root] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
        que.emplace(0, root);
        while (!que.empty()) {
            auto [d, v] = que.top();
            que.pop();
            if (d > dist[v]) continue;
            for (const auto& [nv, cost] : g[v]) {
                if (nv == 0) continue;
                if (dist[v] + cost < dist[nv]) {
                    dist[nv] = dist[v] + cost;
                    que.emplace(dist[nv], nv);
                }
            }
        }

        for (const auto &[goal, wg] : next) {
            if (root == goal) continue;
            if (dist[goal] >= INF) continue;
            ans = min(ans, w0 + dist[goal] + wg);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}