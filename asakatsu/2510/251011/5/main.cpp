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
    ll n, m, nq;
    cin >> n >> m >> nq;
    vector<tuple<ll, ll, ll, ll>> edge(m+nq);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        edge[i] = { w, a, b, -1 };
    }

    for (ll qi = 0; qi < nq; ++qi) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        edge[m+qi] = { w, u, v, qi };
    }
    sort(edge.begin(), edge.end());

    atcoder::dsu g(n);
    vector<bool> ans(nq);
    for (const auto &[w, u, v, qi] : edge) {
        if (qi == -1) {
            g.merge(u, v);
        } else {
            ans[qi] = g.leader(u) != g.leader(v);
        }
    }

    for (ll qi = 0; qi < nq; ++qi) {
        cout << (ans[qi] ? "Yes" : "No") << endl;
    }

    return 0;
}