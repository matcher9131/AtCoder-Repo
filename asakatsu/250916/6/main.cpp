#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<tuple<ll, ll, ll>> edge(m+n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        edge[i] = { w, a, b };
    }
    for (ll i = 0; i < n; ++i) {
        edge[m+i] = { c[i], i, n };
    }
    sort(edge.begin(), edge.end());

    atcoder::dsu uf(n+1);
    ll ans = 0;
    for (const auto &[w, a, b] : edge) {
        if (uf.leader(a) != uf.leader(b)) {
            uf.merge(a, b);
            ans += w;
        }
    }

    cout << ans << endl;

    return 0;
}