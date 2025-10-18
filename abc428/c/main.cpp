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
    return min(a, b);
}
S e() {
    return INF;
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll nq;
    cin >> nq;

    SegTree seg(nq+1);
    seg.set(0, 0);
    ll i = 1;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            char c;
            cin >> c;
            ll newValue = seg.get(i-1) + (c == '(' ? 1 : -1);
            seg.set(i, newValue);
            ++i;
            cout << (newValue == 0 && seg.prod(0, i) >= 0 ? "Yes" : "No") << endl;
        } else {
            --i;
            cout << (seg.get(i-1) == 0 && seg.prod(0, i) >= 0 ? "Yes" : "No") << endl;
        }
    }

    return 0;
}