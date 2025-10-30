#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
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
using LazySegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    LazySegTree seg(n);
    for (ll i = 0; i < n; ++i) {
        seg.apply(0, n-i, (i+1) * (s[i] - '0'));
    }

    string ans;
    for (ll i = 0; i < n-1; ++i) {
        ll val = seg.get(i);
        ans += (val % 10) + '0';
        seg.set(i+1, seg.get(i+1) + val / 10);
    }
    reverse(ans.begin(), ans.end());
    cout << to_string(seg.get(n-1)) << ans << endl; 

    return 0;
}