#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

using S1 = ll;
S1 op1(S1 a, S1 b) {
    return max(a, b);
}
S1 e1() {
    return -INF;
}
using SegTree1 = atcoder::segtree<S1, op1, e1>;

using S2 = ll;
S2 op2(S2 a, S2 b) {
    return min(a, b);
}
S2 e2() {
    return INF;
}
using SegTree2 = atcoder::segtree<S2, op2, e2>;

int main() {
    ll n, nq;
    cin >> n >> nq;
    SegTree1 z1(n), w1(n);
    SegTree2 z2(n), w2(n);
    for (ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        z1.set(i, x+y);
        z2.set(i, x+y);
        w1.set(i, x-y);
        w2.set(i, x-y);
    }

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i, x, y;
            cin >> i >> x >> y;
            --i;
            z1.set(i, x+y);
            z2.set(i, x+y);
            w1.set(i, x-y);
            w2.set(i, x-y);
        } else {
            ll l, r, x, y;
            cin >> l >> r >> x >> y;
            --l;
            ll z0 = x+y;
            ll w0 = x-y;
            cout << max({ abs(z1.prod(l, r) - z0), abs(z2.prod(l, r) - z0), abs(w1.prod(l, r) - w0), abs(w2.prod(l, r) - w0) }) << endl;
        }
    }

    return 0;
}