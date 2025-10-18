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

    auto bfs = [&](ll root) {
        vector<ll> dist(n, INF);
        dist[root] = 0;
        queue<ll> que;
        que.push(root);
        while (!que.empty()) {
            ll v = que.front();
            que.pop();
            for (const ll nv : g[v]) {
                if (dist[nv] < INF) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        return dist;
    };

    vector<ll> dist0 = bfs(0);
    ll dist0Max = *max_element(dist0.begin(), dist0.end());
    ll u = -1;
    for (ll i = n - 1; i >= 0; --i) {
        if (dist0[i] == dist0Max) {
            u = i;
            break;
        }
    }
    vector<ll> distU = bfs(u);
    ll distUMax = *max_element(distU.begin(), distU.end());
    ll v = -1;
    for (ll i = n - 1; i >= 0; --i) {
        if (distU[i] == distUMax) {
            v = i;
            break;
        }
    }
    vector<ll> distV = bfs(v);

    for (ll i = 0; i < n; ++i) {
        ll ans = distU[i] > distV[i] ? u : distU[i] < distV[i] ? v : max(u, v);
        cout << ans+1 << endl;
    }    

    return 0;
}