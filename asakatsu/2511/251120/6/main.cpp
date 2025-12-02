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
    ll n, m;
    cin >> n >> m;
    vector<ll> rc(m);
    vector<ll> c(1e5+1);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++c[x];
        ++rc[x%m];
    }

    vector<ll> pc(m);
    for (ll i = 0; i < (ll)c.size(); ++i) {
        pc[i%m] += c[i] / 2;
    }

    ll ans = rc[0] / 2;
    if (m%2 == 0) ans += rc[m/2] / 2;
    for (ll i = 1; i <= (m-1)/2; ++i) {
        ll p = min(rc[i], rc[m-i]);
        ans += p;
        rc[i] -= p;
        rc[m-i] -= p;
    }

    for (ll i = 1; i <= (m-1)/2; ++i) {
        ans += min(rc[i] / 2, pc[i]);
        ans += min(rc[m-i] / 2, pc[m-i]);
    }

    cout << ans << endl;

    return 0;
}