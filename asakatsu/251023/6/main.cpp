#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

using S = ll;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return 0;
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll n, m;
    cin >> n >> m;
    // r, l
    vector<pair<ll, ll>> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i].second >> p[i].first;
        ++p[i].first;
    }
    ll segLen = 1e5+1;
    SegTree a(segLen);
    for (ll j = 0; j < m; ++j) {
        ll aj;
        cin >> aj;
        a.set(aj, a.get(aj) + 1);
    }
    sort(p.begin(), p.end());

    ll ans = 0;
    for (const auto &[r, l] : p) {
        if (a.prod(l, r) > 0) {
            ++ans;
            ll k = a.max_right(l, [](ll val) { return val == 0; });
            a.set(k, a.get(k) - 1);
        }
    }
    cout << ans << endl;

    return 0;
}