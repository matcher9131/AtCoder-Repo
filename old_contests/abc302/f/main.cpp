#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> s(n);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        for (ll j = 0; j < ai; ++j) {
            ll sij;
            cin >> sij;
            --sij;
            s[i].push_back(sij);
        }
    }

    vector<vector<ll>> g(n+m);
    for (ll i = 0; i < n; ++i) {
        for (const ll sij : s[i]) {
            g[i].push_back(n + sij);
            g[n + sij].push_back(i);
        }
    }

    vector<ll> dist(n+m, INF);
    dist[n] = 0;
    queue<ll> que;
    que.push(n);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        for (const ll nv : g[v]) {
            if (dist[nv] < INF) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << (dist[n+m-1] == INF ? -1 : (dist[n+m-1] - 2) / 2) << endl;

    return 0;
}