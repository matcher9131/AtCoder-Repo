#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

using S = ll;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll n, nq;
    cin >> n >> nq;
    string s;
    cin >> s;

    SegTree seg(n-1);
    for (ll i = 0; i < n-1; ++i) {
        seg.set(i, s[i] != s[i+1]);
    }

    while (nq--) {
        ll type, l, r;
        cin >> type >> l >> r;
        --l;
        --r;
        if (type == 1) {
            if (l > 0) seg.set(l-1, !seg.get(l-1));
            if (r < n-1) seg.set(r, !seg.get(r));
        } else {
            if (l == r) cout << "Yes" << endl;
            else cout << (seg.prod(l, r) == r-l ? "Yes" : "No") << endl;
        }
    }

    return 0;
}