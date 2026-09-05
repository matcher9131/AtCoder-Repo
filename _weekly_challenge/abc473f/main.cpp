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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll nq;
    cin >> nq;

    LazySegTree seg(n+1);
    seg.set(0, 0);
    for (ll i = 0; i < n; ++i) {
        seg.set(i+1, seg.get(i) + (s[i] == 'A' ? 1 : -1));
    }

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i;
            char c;
            cin >> i >> c;
            --i;
            F dif = (c == 'A' ? 1 : -1) - (s[i] == 'A' ? 1 : -1);
            seg.apply(i+1, n+1, dif);
            s[i] = c;
        } else {
            ll l, r;
            cin >> l >> r;
            ++r;
            ll al = seg.get(l-1);
            cout << (seg.prod(l, r) >= al ? "Yes" : "No") << endl;
        }
    }

    return 0;
}