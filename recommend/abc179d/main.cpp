#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

using S = mint;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}
using F = mint;
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
    ll n, k;
    cin >> n >> k;
    vector<ll> l(k), r(k);
    ll sum = 0;
    for (ll i = 0; i < k; ++i) {
        cin >> l[i] >> r[i];
        ++r[i];
        sum += r[i] - l[i];
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> dp(n);
    dp.set(0, 1);
    for (ll i = 0; i < n; ++i) {
        for (ll ki = 0; ki < k; ++ki) {
            dp.apply(min(i + l[ki], n), min(i + r[ki], n), dp.get(i));
        }
    }

    cout << dp.get(n-1).val() << endl;
    
    return 0;
}