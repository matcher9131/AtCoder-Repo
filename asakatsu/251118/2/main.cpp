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
    vector<unordered_set<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            for (ll k = j+1; k < n; ++k) {
                if (g[i].contains(j) && g[j].contains(k) && g[k].contains(i)) ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}