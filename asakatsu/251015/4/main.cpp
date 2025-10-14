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

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (i == 0 || i == n-1 || (a[i-1] < a[i] && a[i] > a[i+1])) {
            ll l = i, r = i;
            while (l > 0 && a[l-1] < a[l]) --l;
            while (r < n-1 && a[r] > a[r+1]) ++r;
            chmax(ans, r-l+1);
        }
    }
    cout << ans << endl;

    return 0;
}