#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

using S = ll;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}


int main() {
    ll nq;
    cin >> nq;

    ll n = 2.8e6;
    vector<ll> v(n, 1);
    atcoder::segtree<S, op, e> seg(v);
    unordered_set<ll> deleted;
    
    while (nq--) {
        ll a, b;
        cin >> a >> b;

        if (!deleted.contains(a)) {
            for (ll i = a; i < n; i += a) {
                seg.set(i, 0);
            }
            deleted.insert(a);
        }
        auto f = [&](ll x) { return x <= b; };
        cout << seg.max_right(0, f) << endl;
    }

    return 0;
}