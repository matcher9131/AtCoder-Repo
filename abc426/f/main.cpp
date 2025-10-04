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
    ll val;
    ll add;
};
S op(S a, S b) {
    return {a.val + b.val, a.add + b.add};
}
S e() {
    return {0, 0};
}
using F = S;
S mapping(F f, S x) {
    return max(f+x, 0LL);
}
F composition(F f, F g) {
    return f+g;
}
F id() {
    return 0;
}

int main() {
    ll n;
    cin >> n;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        seg.set(i, ai);
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll l, r, k;
        cin >> l >> r >> k;
        --l;
        ll before = seg.prod(l, r);
        seg.apply(l, r, -k);
        ll after = seg.prod(l, r);
        cout << before-after << endl;
        printf("before = %lld, after = %lld\n", before, after);
        for (ll i = 0; i < n; ++i) {
            cout << seg.get(i) << " \n"[i == n - 1];
        }
    }

    return 0;
}