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
    return a + b;
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
    ll n, m;
    cin >> n >> m;
    LazySegTree a(n);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a.set(i, ai);
    }
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }

    for (ll j = 0; j < m; ++j) {
        ll x = a.get(b[j]);
        a.set(b[j], 0);
        ll q = x/n, r = x%n;
        a.apply(0, n, q);
        ll left = b[j]+1, right = b[j]+1+r;
        if (right <= n) {
            a.apply(left, right, 1);
        } else if (left < n) {
            a.apply(left, n, 1);
            a.apply(0, right%n, 1);
        } else {
            a.apply(left%n, right%n, 1);
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << a.get(i) << " \n"[i == n - 1];
    }


    return 0;
}