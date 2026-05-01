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

struct S {
    mint sq;
    mint val;
    ll len;
};
S op(S a, S b) {
    return { a.sq + b.sq, a.val + b.val, a.len + b.len };
}
S e() {
    return {0, 0, 0};
}
using F = mint;
S mapping(F f, S x) {
    return { x.sq + 2 * f * x.val + f * f * x.len, x.val + f * x.len, x.len };
}
F composition(F f, F g) {
    return f + g;
}
F id() {
    return 0;
}
using LazySegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    ll n, nq;
    cin >> n >> nq;

    LazySegTree seg(n);
    for (ll i = 0; i < n; ++i) {
        seg.set(i, { 0, 0, 1 });
    }

    while (nq--) {
        ll l, r, x;
        cin >> l >> r >> x;
        --l;
        seg.apply(l, r, x);
        S section = seg.prod(l, r);
        mint ans = (section.val * section.val - section.sq) / 2;
        cout << ans.val() << endl;
    }

    return 0;
}