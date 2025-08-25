#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

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


int main() {
    ll n, m;
    cin >> n >> m;
    // seg[r] = lの集合
    vector<vector<ll>> seg(n);
    for (ll i = 0; i < m; ++i) {
        ll li, ri;
        cin >> li >> ri;
        --li;
        --ri;
        seg[ri].push_back(li);
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> a(n);
    ll ans = 0;
    for (ll ri = 0; ri < n; ++ri) {
        for (const ll li : seg[ri]) {
            ans += a.get(li);
        }
        for (const ll li : seg[ri]) {
            a.apply(li+1, ri, 1);
        }
    }

    cout << ans << endl;

    return 0;
}