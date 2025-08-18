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
    vector<ll> l(n), r(n);
    vector<ll> a(2*n);
    for (ll i = 0; i < n; ++i) {
        ll xi, ri;
        cin >> xi >> ri;
        l[i] = xi - ri;
        r[i] = xi + ri;
        a[2*i] = l[i];
        a[2*i+1] = r[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (ll i = 0; i < n; ++i) {
        l[i] = lower_bound(a.begin(), a.end(), l[i]) - a.begin();
        r[i] = lower_bound(a.begin(), a.end(), r[i]) - a.begin();
    }

    vector<vector<ll>> ls(2*n);
    for (ll i = 0; i < n; ++i) {
        ls[r[i]].push_back(l[i]);
    }

    atcoder::segtree<S, op ,e> dp(2*n);
    for (ll i = 0; i < 2*n; ++i) {
        vector<ll> vals;
        for (const ll left : ls[i]) {
            vals.push_back(dp.prod(left+1, 2*n) + 1);
        }
        for (ll j = 0; j < (ll)vals.size(); ++j) {
            dp.set(ls[i][j], max(dp.get(ls[i][j]), vals[j]));
        }
    }

    cout << dp.all_prod() << endl;

    return 0;
}