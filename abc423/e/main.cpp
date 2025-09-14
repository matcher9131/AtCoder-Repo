#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

struct S {
    ll val;
    ll sum;
    ll lsum;
    ll rsum;
    ll l;
    ll r;
};
S op(S a, S b) {
    if (a.l == -1) return b;
    if (b.l == -1) return a;
    if (a.l > b.r) swap(a, b);
    ll ca = a.r - a.l + 1;
    ll cb = b.r - b.l + 1;
    return {
        a.val + b.val + cb * a.rsum + ca * b.lsum,
        a.sum + b.sum,
        a.lsum + b.lsum + cb * a.sum,
        a.rsum + b.rsum + ca * b.sum,
        a.l,
        b.r
    };
}
S e() {
    return {
        0,
        0,
        0,
        0,
        -1,
        -1
    };
}


int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    atcoder::segtree<S, op, e> seg(n);
    for (ll i = 0; i < n; ++i) {
        seg.set(i, { a[i], a[i], a[i], a[i], i, i });
    }

    while (nq--) {
        ll l, r;
        cin >> l >> r;
        --l;
        cout << seg.prod(l, r).val << endl;
    }

    return 0;
}