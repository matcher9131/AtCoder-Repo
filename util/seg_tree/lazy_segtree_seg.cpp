#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using ll = long long;
using namespace std;

// A[i]のうち有効なもののみの和を求める
// A[i] = { A[i], 1 } で初期化
// f = 1で有効化, f = 0で無効化

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
using F = optional<ll>;
S mapping(F f, S x) {
    return f ? S{ *f * x.len, x.len } : x;
}
F composition(F f, F g) {
    return f ? f : g;
}
F id() {
    return {};
}
using LazySegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
