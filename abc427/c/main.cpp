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
    vector<set<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }

    ll ans = INF;
    for (ll bit = 0; bit < 1LL<<n; ++bit) {
        ll res = 0;
        for (ll i = 0; i < n; ++i) {
            for (ll j = i+1; j < n; ++j) {
                if (((bit >> i) & 1LL) ^ ((bit >> j) & 1LL)) continue;
                if (g[i].contains(j)) ++res;
            }
        }
        chmin(ans, res);
    }
    cout << ans << endl;

    return 0;
}