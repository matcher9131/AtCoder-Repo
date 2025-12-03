#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
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
    vector<tuple<ll, ll, ll>> edge(n-1);
    for (ll i = 0; i < n-1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        edge[i] = { w, u, v };
    }
    sort(edge.begin(), edge.end());

    atcoder::dsu g(n);
    ll ans = 0;
    for (const auto &[w, u, v] : edge) {
        ll c1 = g.size(u);
        ll c2 = g.size(v);
        ans += w * c1 * c2;
        g.merge(u, v);
    }
    cout << ans << endl;

    return 0;
}