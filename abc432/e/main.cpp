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
    return a + b;
}
S e() {
    return 0;
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll n, nq;
    cin >> n >> nq;
    SegTree count(5e5+2), sum(5e5+2);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        count.set(a[i], count.get(a[i]) + 1);
        sum.set(a[i], sum.get(a[i]) + a[i]);
    }

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, y;
            cin >> x >> y;
            --x;
            count.set(a[x], count.get(a[x]) - 1);
            sum.set(a[x], sum.get(a[x]) - a[x]);
            count.set(y, count.get(y) + 1);
            sum.set(y, sum.get(y) + y);
            a[x] = y;
        } else {
            ll l, r;
            cin >> l >> r;
            ll ans = l > r ? l * n : l * count.prod(0, l) + sum.prod(l, r) + r * count.prod(r, 5e5+2);
            cout << ans << "\n";
        }
    }

    return 0;
}