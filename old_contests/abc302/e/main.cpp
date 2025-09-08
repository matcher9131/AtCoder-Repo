#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    cin >> n >> nq;

    vector<unordered_set<ll>> g(n);
    ll ans = n;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            if (g[u].empty()) --ans;
            if (g[v].empty()) --ans;
            g[u].insert(v);
            g[v].insert(u);
        } else {
            ll v;
            cin >> v;
            --v;
            for (const ll to : g[v]) {
                g[to].erase(v);
                if (g[to].empty()) ++ans;
            }
            if (!g[v].empty()) ++ans;
            g[v].clear();
        }
        cout << ans << endl;
    }

    return 0;
}