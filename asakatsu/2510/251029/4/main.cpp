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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    for (const ll bi : b) {
        ll ca = lower_bound(a.begin(), a.end(), bi) - a.begin();
        ll cc = c.end() - upper_bound(c.begin(), c.end(), bi);
        ans += ca * cc;
    }
    cout << ans << endl;

    return 0;
}