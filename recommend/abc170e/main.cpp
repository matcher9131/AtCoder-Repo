#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

using S = ll;
S op(S a, S b) {
    return min(a, b);
}
S e() {
    return INF;
}

int main() {
    ll m = 2e5;
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(n), b(n);
    atcoder::segtree<S, op, e> seg(m);
    vector<map<ll, ll, greater<>>> kinder(m);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        --b[i];
        ++kinder[b[i]][a[i]];
        seg.set(b[i], kinder[b[i]].begin()->first);
    }
    

    while (nq--) {
        ll i, to;
        cin >> i >> to;
        --i;
        --to;
        ll from = b[i];
        b[i] = to;
        
        --kinder[from][a[i]];
        if (kinder[from][a[i]] == 0) kinder[from].erase(a[i]);
        if (kinder[from].empty()) {
            seg.set(from, INF);
        } else {
            seg.set(from, kinder[from].begin()->first);
        }

        ++kinder[to][a[i]];
        seg.set(to, kinder[to].begin()->first);

        cout << seg.all_prod() << endl;
    }

    return 0;
}