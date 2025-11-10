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
    ll n, m;
    cin >> n >> m;
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
    queue<ll> que;
    que.push(0);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        for (const ll nv : g[v]) {
            if (dist[nv] < INF) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << (dist[n-1] <= 2 ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;
}