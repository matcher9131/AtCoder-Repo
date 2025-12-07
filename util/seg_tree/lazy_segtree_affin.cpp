#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using ll = long long;

// アフィン変換

struct S {
    ll sum;
    ll len;
};
S op(S a, S b) {
    return { a.sum + b.sum, a.len + b.len };
}
S e() {
    return {0, 0};
}
struct F {
    ll mul;
    ll add;
};
S mapping(F f, S x) {
    return { f.mul * x.sum + f.add * x.len, x.len };
}
F composition(F f, F g) {
    return { f.mul * g.mul, f.mul * g.add + f.add };
}
F id() {
    return {1, 0};
}
using LazySegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
