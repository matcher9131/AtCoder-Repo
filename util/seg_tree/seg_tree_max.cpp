#include <atcoder/segtree>
#include <algorithm>
using namespace std;
using ll = long long;

using S = ll;
S op(S a, S b) {
    return max(a, b);
}
S e() {
    return 0;
}
using SegTree = atcoder::segtree<S, op, e>;