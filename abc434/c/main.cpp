#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n, h0;
    cin >> n >> h0;
    vector<ll> t(n), l(n), u(n);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i] >> l[i] >> u[i];
    }
    ll cl = h0, cu = h0;
    ll pt = 0;
    for (ll i = 0; i < n; ++i) {
        cu += t[i] - pt;
        cl -= t[i] - pt;
        chmax(cl, 0LL);
        if (cu < l[i] || u[i] < cl) {
            cout << "No" << endl;
            return;
        }
        chmax(cl, l[i]);
        chmin(cu, u[i]);
        pt = t[i];
    }
    cout << "Yes" << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}