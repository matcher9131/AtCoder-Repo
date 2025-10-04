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
    ll sum;
    int length;
};
S op(S a, S b) {
    return { a.sum + b.sum, a.length + b.length };
}
S e() {
    return {0, 0};
}
struct F {
    ll mul;
    ll add;
};
S mapping(F f, S x) {
    return { f.mul * x.sum + f.add * x.length, x.length };
}
F composition(F f, F g) {
    return { f.mul * g.mul, f.mul * g.add + f.add };
}
F id() {
    return {1, 0};
}

int main() {
    ll n, nq;
    cin >> n >> nq;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n+1);
    for (ll i = 0; i < n; ++i) {
        seg.set(i, {1,1});
    }

    while (nq--) {
        ll x, y;
        cin >> x >> y;
        --x;
        --y;
        ll ans = seg.prod(0, x+1).sum;
        cout << ans << endl;
        seg.apply(0, x+1, {0,0});
        seg.set(y, {seg.get(y).sum + ans, 1});
    }

    return 0;
}