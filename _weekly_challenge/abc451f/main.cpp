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
    ll n, nq;
    cin >> n >> nq;

    atcoder::dsu d(n);
    vector<vector<unordered_set<ll>>> c(n, vector<unordered_set<ll>>(2));
    for (ll i = 0; i < n; ++i) {
        c[i][0].insert(i);
    }

    bool impossible = false;
    ll ans = 0;
    while (nq--) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;

        if (impossible) {
            cout << -1 << endl;
            continue;
        }

        ll i = d.leader(u);
        ll j = d.leader(v);
        bool differs = c[i][0].contains(u) ^ c[j][0].contains(v);
        if (i == j) {
            if (!differs) {
                impossible = true;
                cout << -1 << endl;
            } else {
                cout << ans << endl;
            }
        } else {
            if (d.size(i) < d.size(j)) {
                swap(i, j);
            }

            ans -= min(c[i][0].size(), c[i][1].size());
            ans -= min(c[j][0].size(), c[j][1].size());

            for (const ll jj : c[j][0]) {
                c[i][1 ^differs].insert(jj);
            }
            for (const ll jj : c[j][1]) {
                c[i][differs].insert(jj);
            }
            c[j] = vector<unordered_set<ll>>(2);

            ll np = d.merge(i, j);
            if (np != i) c[np] = c[i];

            ans += min(c[np][0].size(), c[np][1].size());

            cout << ans << endl;
        }
    }

    return 0;
}