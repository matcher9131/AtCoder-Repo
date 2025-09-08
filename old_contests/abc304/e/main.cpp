#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;


int main() {
    int n, m;
    cin >> n >> m;
    atcoder::dsu g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g.merge(a, b);
    }
    ll k;
    cin >> k;
    set<pair<ll, ll>> banned;
    for (ll i = 0; i < k; ++i) {
        ll x, y;
        cin >> x >> y;
        --x;
        --y;
        int r1 = g.leader(x);
        int r2 = g.leader(y);
        if (r1 > r2) swap(r1, r2);
        banned.emplace(r1, r2);
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll p, q;
        cin >> p >> q;
        --p;
        --q;
        int r1 = g.leader(p);
        int r2 = g.leader(q);
        if (r1 > r2) swap(r1, r2);
        cout << (!banned.contains({r1, r2}) ? "Yes" : "No") << endl;
    }

    return 0;
}