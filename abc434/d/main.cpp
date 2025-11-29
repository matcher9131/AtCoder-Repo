#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

struct S {
    ll sum;
    int length;
};
S op(S a, S b) {
    return { a.sum + b.sum, a.length + b.length };
}
S e() {
    return {0, 0};
}
struct F {
    ll mul;
    ll add;
};
S mapping(F f, S x) {
    return { f.mul * x.sum + f.add * x.length, x.length };
}
F composition(F f, F g) {
    return { f.mul * g.mul, f.mul * g.add + f.add };
}
F id() {
    return {1, 0};
}
using LazySegTree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    ll n;
    cin >> n;
    vector<ll> u(n), d(n), l(n), r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> u[i] >> d[i] >> l[i] >> r[i];
        ++d[i];
        ++r[i];
    }

    vector<vector<ll>> sky(2002, vector<ll>(2002));
    for (ll i = 0; i < n; ++i) {
        ++sky[u[i]][l[i]];
        ++sky[d[i]][r[i]];
        --sky[u[i]][r[i]];
        --sky[d[i]][l[i]];
    }
    for (ll i = 0; i < 2002; ++i) {
        for (ll j = 1; j < 2002; ++j) {
            sky[i][j] += sky[i][j-1];
        }
    }
    for (ll j = 0; j < 2002; ++j) {
        for (ll i = 1; i < 2002; ++i) {
            sky[i][j] += sky[i-1][j];
        }
    }

    ll covered = 0;
    for (ll i = 0; i < 2002; ++i) {
        for (ll j = 0; j < 2002; ++j) {
            if (sky[i][j] > 0) ++covered;
            if (sky[i][j] > 1) sky[i][j] = 0;
        }
    }

    vector<vector<ll>> s(2003, vector<ll>(2003));
    for (ll i = 0; i < 2002; ++i) {
        for (ll j = 0; j < 2002; ++j) {
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + sky[i][j];
        }
    }

    for (ll i = 0; i < n; ++i) {
        ll dif = s[d[i]][r[i]] - s[d[i]][l[i]] - s[u[i]][r[i]] + s[u[i]][l[i]];
        cout << 2000*2000 - covered + dif << "\n";
    }

    

    

    return 0;
}