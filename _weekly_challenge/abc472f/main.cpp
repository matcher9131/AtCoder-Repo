#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

struct S {
    ll mx;
    ll my;
    ll s;
};
S op(S a, S b) {
    if (a.s == 0 && b.s == 0) return { 0, 0, 0 };
    return {
        a.mx + b.mx,
        a.my + b.my,
        a.s + b.s
    };
}
S e() {
    return { 0, 0, 0 };
}
using SegTree = atcoder::segtree<S, op, e>;

int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    auto f = [&](ll i, ll j, ll k) -> S {
        ll s = abs(x[i] * (y[j] - y[k]) + x[j] * (y[k] - y[i]) + x[k] * (y[i] - y[j]));
        ll mx = (x[i] + x[j] + x[k]) * s;
        ll my = (y[i] + y[j] + y[k]) * s;
        return { mx, my, s };
    };

    SegTree tri(n-2);
    for (ll i = 0; i < n-2; ++i) {
        tri.set(i, f(0, i+1, i+2));
    }

    S all = tri.all_prod();

    cout << fixed << setprecision(15);
    while (nq--) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;

        if (u == 0) {
            S ans = tri.prod(0, v-1);
            cout << ans.mx / (double)ans.s / 3.0 << " " << ans.my / (double)ans.s / 3.0 << endl;
        } else if (v == 0) {
            S ans = tri.prod(u-1, n-2);
            cout << ans.mx / (double)ans.s / 3.0 << " " << ans.my / (double)ans.s / 3.0 << endl;
        } else if (u < v) {
            S left = tri.prod(0, u-1);
            S right = tri.prod(v-1, n-2);
            S mid = f(0, u, v);
            S part = op(op(left, mid), right);
            S inv = { -part.mx, -part.my, -part.s };
            S ans = op(all, inv);
            cout << ans.mx / (double)ans.s / 3.0 << " " << ans.my / (double)ans.s / 3.0 << endl;
        } else {
            S left = tri.prod(0, v-1);
            S right = tri.prod(u-1, n-2);
            S mid = f(0, u, v);
            S ans = op(op(left, mid), right);
            cout << ans.mx / (double)ans.s / 3.0 << " " << ans.my / (double)ans.s / 3.0 << endl;
        }
    }

    return 0;
}