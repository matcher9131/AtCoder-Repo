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
    atcoder::dsu g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g.merge(a, b);
    }

    ll ans = -m;
    for (const auto &group : g.groups()) {
        ll size = group.size();
        ans += size * (size - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}