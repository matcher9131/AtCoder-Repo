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
    vector<ll> c(2e5+1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i]];
    }

    ll ans = 0;
    for (ll i = 0; i < 2e5+1; ++i) {
        if (c[i] >= 2) {
            ans += c[i] * (c[i] - 1) / 2 * (n - c[i]);
        }
    }
    cout << ans << endl;

    return 0;
}