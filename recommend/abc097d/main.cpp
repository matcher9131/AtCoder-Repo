#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    atcoder::dsu d(n);
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        --x;
        --y;
        d.merge(x, y);
    }

    ll ans = 0;
    for (const auto &v : d.groups()) {
        set<ll> s;
        for (const int i : v) {
            s.insert(p[i]);
        }
        for (const int i : v) {
            if (s.contains(i)) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}