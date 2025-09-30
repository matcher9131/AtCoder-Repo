#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, nq;
    cin >> n >> nq;

    vector<set<ll>> g(n);
    ll ans = n;

    while (nq--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            if (g[u].empty()) --ans;
            if (g[v].empty()) --ans;
            g[u].insert(v);
            g[v].insert(u);            
        } else {
            ll u;
            cin >> u;
            --u;
            for (const ll v : g[u]) {
                g[v].erase(u);
                if (g[v].empty()) ++ans;
            }
            if (!g[u].empty()) ++ans;
            g[u].clear();
        }
        cout << ans << endl;
    }

    return 0;
}