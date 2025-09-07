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
    vector<ll> w(n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i];
    }
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    // v, cw, dist
    vector<map<ll, ll>> dist(n);
    vector<ll> distMax(n);
    dist[0][0] = 0;
    // dist, v, cw
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    que.emplace(0, 0, 0);
    while (!que.empty()) {
        auto [d, v, cw] = que.top();
        que.pop();
        if (dist[v].contains(cw) && d > dist[v][cw]) continue;
        if (!dist[v].empty() && dist[v].rbegin()->first <= cw && d > distMax[v]) continue;
        ll nw = cw + w[v];
        for (const ll& nv : g[v]) {
            if (!dist[nv].empty() && dist[nv].rbegin()->first < nw) continue;
            if (!dist[nv].contains(nw) || dist[v][cw] + nw < dist[nv][nw]) {
                dist[nv][nw] = dist[v][cw] + nw;
                distMax[nv] = max(distMax[nv], dist[nv][nw]);
                que.emplace(dist[nv][nw], nv, nw);
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        ll ans = INF;
        for (const auto &[_, d] : dist[i]) {
            ans = min(ans, d);
        }
        cout << ans << endl;
    }

    return 0;
}