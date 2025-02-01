// #include <atcoder/segtree>

using S = int;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}

// atcoder::segtree<S, op, e> seg(n);