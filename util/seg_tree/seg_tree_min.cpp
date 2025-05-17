#include <atcoder/segtree>
#include <algorithm>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;
using S = ll;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}
