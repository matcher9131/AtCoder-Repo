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
    return max(a, b);
}
S e() {
    return 0;
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll m = 3e5+1;
    SegTree seg(m);
    for (ll i = 0; i < n; ++i) {
        ll newValue = seg.prod(max(a[i]-k, 0LL), min(a[i]+k+1, m)) + 1;
        if (seg.get(a[i]) < newValue) seg.set(a[i], newValue);
    }
    cout << seg.all_prod() << endl;

    return 0;
}