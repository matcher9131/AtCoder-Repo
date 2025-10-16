#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

using S = ll;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
using F = ll;
S mapping(F f, S x) {
    return f + x;
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}
using LazySegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    ll n, k;
    cin >> n >> k;
    LazySegTree seg(n);
    for (ll i = 0; i < n; ++i) {
        seg.set(i, 0);
    }
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        seg.set(ai, seg.get(ai) + 1);
    }

    ll ans = 0;
    while (k--) {
        ll r = seg.max_right(0, [&](S x) { return x > 0; });
        ans += r;
        seg.apply(0, r, -1);
    }
    cout << ans << endl;

    return 0;
}