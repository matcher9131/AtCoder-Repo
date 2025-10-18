#include <atcoder/segtree>
using ll = long long;

using S = ll;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
using SegTree = atcoder::segtree<S, op, e>;