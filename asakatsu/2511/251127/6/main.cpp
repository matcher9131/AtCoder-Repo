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
    vector<vector<pair<ll, ll>>> g(n);
    vector<ll> c(m), d(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b >> c[i] >> d[i];
        --a; --b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }

    auto f = [](ll t, ll c, ll d) -> ll {
        return t + c + d / (t+1);
    };

    auto getArrived = [&](ll start, ll c, ll d) -> ll {
        ll t = (ll)sqrt(d) - 1;
        if (start > t+1) {
            return f(start, c, d);
        } else if (start > t) {
            return f(t+1, c, d);
        } else {
            return min(f(t, c, d), f(t+1, c, d));
        }
    };

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        auto [ds, v] = que.top();
        que.pop();
        if (ds > dist[v]) continue;
        for (const auto& [nv, ei] : g[v]) {
            ll nd = getArrived(ds, c[ei], d[ei]);
            if (nd < dist[nv]) {
                dist[nv] = nd;
                que.emplace(dist[nv], nv);
            }
        }
    }
    cout << (dist[n-1] == INF ? -1 : dist[n-1]) << endl;

    return 0;
}