#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

struct S {
    mint val;
    int size;
};
S op(S a, S b) {
    return { a.val + b.val, a.size + b.size };
}
S e() {
    return {0, 0};
}
struct F {
    mint b;
    mint c;
};
S mapping(F f, S x) {
    return { f.b * x.val + f.c * x.size, x.size };
}
F composition(F f, F g) {
    return { f.b * g.b, f.b * g.c + f.c };
}
F id() {
    return {1, 0};
}

int main() {
    ll n, m;
    cin >> n >> m;
    
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    for (ll i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        seg.set(i, { ai, 1 });
    }

    while (m--) {
        ll l, r;
        cin >> l >> r;
        --l;
        --r;
        mint sum = seg.prod(l, r+1).val;
        mint newVal = sum / (r+1 - l);
        seg.apply(l, r+1, {0, newVal});
    }


    for (ll i = 0; i < n; ++i) {
        cout << seg.prod(i, i+1).val.val() << " \n"[i == n - 1];
    }

    return 0;
}