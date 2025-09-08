#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

using S = ll;
S op(S a, S b) {
    return max(a, b);
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
    ll n, d, w;
    cin >> n >> d >> w;
    vector<tuple<ll, ll, ll>> a(2*n);
    for (ll i = 0; i < n; ++i) {
        ll t, x;
        cin >> t >> x;
        --t;
        --x;
        a[i] = {t, 1, x};
        a[n+i] = {t+d, 0, x};
    }
    sort(a.begin(), a.end());

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(2e5);

    ll ans = 0;
    for (ll i = 0; i < 2*n; ++i) {
        auto [_, type, x] = a[i];
        seg.apply(x, min((ll)2e5, x + w), type == 1 ? 1 : -1);
        ans = max(ans, seg.all_prod());
    }

    cout << ans << endl;
    return 0;
}