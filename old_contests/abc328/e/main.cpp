#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;


int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<tuple<ll, ll, ll>> e(m);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        e[i] = { u, v, w };
    }

    ll ans = k;
    // numEdges, val, uf
    vector<tuple<ll, ll, atcoder::dsu>> vec;
    vec.emplace_back(0, 0, atcoder::dsu(n));
    for (ll ei = 0; ei < m; ++ei) {
        auto [u, v, w] = e[ei];
        decltype(vec) tmp;
        for (auto &[numEdges, val, uf] : vec) {
            if (!uf.same(u, v)) {
                ll newValue = (val + w) % k;
                if (numEdges == n-2) {
                    ans = min(ans, newValue);
                }
                auto uf2 = uf;
                uf2.merge(u, v);
                tmp.emplace_back(numEdges + 1, newValue, uf2);
            }
        }
        for (const auto &tt : tmp) {
            vec.push_back(tt);
        }
    }

    cout << ans << endl;
    return 0;
}