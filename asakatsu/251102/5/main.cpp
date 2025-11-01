#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
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
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }

    atcoder::scc_graph g(n);
    for (ll i = 0; i < n; ++i) {
        g.add_edge(i, x[i]);
    }
    auto groups = g.scc();

    ll ans = 0;
    for (const auto &group : groups) {
        if (group.size() == 1) continue;
        ll cur = INF;
        for (const ll v : group) {
            chmin(cur, c[v]);
        }
        ans += cur;
    }
    cout << ans << endl;

    return 0;
}