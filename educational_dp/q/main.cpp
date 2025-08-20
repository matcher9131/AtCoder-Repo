#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
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

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
        --h[i];
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    atcoder::segtree<S, op, e> dp(n);
    for (ll i = 0; i < n; ++i) {
        dp.set(h[i], max(dp.get(h[i]), dp.prod(0, h[i]) + a[i]));
    }

    cout << dp.all_prod() << endl;

    return 0;
}