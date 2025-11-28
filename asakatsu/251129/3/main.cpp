#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<ll> q(n);
    for (ll i = 0; i < n; ++i) {
        cin >> q[i];
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll ma = INF;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == 0) continue;
        chmin(ma, q[i] / a[i]);
    }

    ll ans = 0;
    for (ll x = 0; x <= ma; ++x) {
        ll y = INF;
        for (ll i = 0; i < n; ++i) {
            if (b[i] == 0) continue;
            chmin(y, (q[i] - x*a[i]) / b[i]);
        }
        chmax(ans, x+y);
    }
    cout << ans << endl;

    return 0;
}