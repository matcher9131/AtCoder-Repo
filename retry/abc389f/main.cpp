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
    return max(a, b);
}
S e() {
    return 0;
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
    ll n;
    cin >> n;
    vector<ll> l(n), r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    constexpr ll M = 5e5;
    LazySegTree seg(M+1);
    for (ll i = 0; i <= M; ++i) {
        seg.set(i, i);
    }
    for (ll i = 0; i < n; ++i) {
        ll li = seg.max_right(0, [&](S x) { return x < l[i]; });
        ll ri = seg.max_right(0, [&](S x) { return x <= r[i]; });
        seg.apply(li, ri, 1);
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll x;
        cin >> x;
        cout << seg.get(x) << endl;
    }

    return 0;
}