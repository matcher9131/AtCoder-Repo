// #include <atcoder/lazysegtree>
#include <algorithm>
using namespace std;
using ll = long long;

extern ll INF;

using S = ll;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return -INF;
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

// atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);